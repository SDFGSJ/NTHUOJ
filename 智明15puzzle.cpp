#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
/*
linear conflict combinations:
2 1 => 2 extra moves
1 2 3 => 0
3 2 1 => 4
other: 2

1 2 3 4 => 0
start with 1, not 1 4 3 2: 2
start with 2, then 3 comes earlier than 4: 2
start with 3/4, rest in order: 2
4 3 2 1: 6
other: 4
*/
class state{
	signed char board[4][4], empty_row, empty_col;
	signed char row_conflicts[4], col_conflicts[4];
	signed char Manhattan_dist_sum, conflicts_sum;
	static int goal_row(const int t){ return t - 1 >> 2; }
	static int goal_col(const int t){ return t - 1 & 3; }

	// used to calculate extra moves from conflicts
	static signed char LIS_DP[4], LIS_length;
	void update_row_conflict(const signed char row){
		signed char ans = 0; LIS_length = 0;
		for (signed char col = 0; col < 4; ++col)
			if (board[row][col] && goal_row(board[row][col]) == row){
				signed char *p = lower_bound(LIS_DP, LIS_DP + LIS_length,
				                             board[row][col]);
				if (p == LIS_DP + LIS_length) ++LIS_length;
				*p = board[row][col];
				++ans;
		}
		ans -= LIS_length;
		conflicts_sum += ans - row_conflicts[row];
		row_conflicts[row] = ans;
	}
	void update_col_conflict(const signed char col){
		signed char ans = 0; LIS_length = 0;
		for (signed char row = 0; row < 4; ++row)
			if (board[row][col] && goal_col(board[row][col]) == col){
				signed char *p = lower_bound(LIS_DP, LIS_DP + LIS_length,
				                             board[row][col]);
				if (p == LIS_DP + LIS_length) ++LIS_length;
				*p = board[row][col];
				++ans;
		}
		ans -= LIS_length;
		conflicts_sum += ans - col_conflicts[col];
		col_conflicts[col] = ans;
	}
public:
	enum direction{DNE, DOWN, RIGHT, UP, LEFT};
	signed char moves_spent;
	state(){
		// the default constructor reads input
		Manhattan_dist_sum = moves_spent = conflicts_sum = 0;
		memset(row_conflicts, 0, 4); memset(col_conflicts, 0, 4);
		for (signed char R = 0; R < 4; ++R){
			for (signed char C = 0; C < 4; ++C){
				scanf("%hhd", board[R] + C);
				if (board[R][C])
					Manhattan_dist_sum += abs(R - goal_row(board[R][C]))
					                    + abs(C - goal_col(board[R][C]));
				else { empty_row = R; empty_col = C; }
			}
			update_row_conflict(R);
		}
		for (signed char C = 0; C < 4; ++C) update_col_conflict(C);
	}
	state(const state& other){ memcpy(this, &other, sizeof(state)); }
	state& operator=(const state& other){
		// if (this != &other)
		memcpy(this, &other, sizeof(state));
		return *this;
	}
	bool move(const direction dir){
		// move the empty tile in the direction of dir
		// does not increment or decrement moves count
		// return whether the move takes place
		switch (dir){
			case DOWN:
				if (empty_row == 3) return false;
				swap(board[empty_row][empty_col],board[empty_row+1][empty_col]);

				// empty_row is the row of the non-empty tile
				// after moving UP
				if (empty_row < goal_row(board[empty_row][empty_col]))
					++Manhattan_dist_sum;
				else --Manhattan_dist_sum;

				if (goal_row(board[empty_row][empty_col]) == empty_row)
					update_row_conflict(empty_row);
				else if (goal_row(board[empty_row][empty_col]) == empty_row+1)
					update_row_conflict(empty_row+1);

				++empty_row; return true;
			case RIGHT:
				if (empty_col == 3) return false;
				swap(board[empty_row][empty_col],board[empty_row][empty_col+1]);

				// empty_col is the column of the non-empty tile
				// after moving LEFT
				if (empty_col < goal_col(board[empty_row][empty_col]))
					++Manhattan_dist_sum;
				else --Manhattan_dist_sum;

				if (goal_col(board[empty_row][empty_col]) == empty_col)
					update_col_conflict(empty_col);
				else if (goal_col(board[empty_row][empty_col]) == empty_col+1)
					update_col_conflict(empty_col+1);

				++empty_col; return true;
			case UP:
				if (!empty_row) return false;
				swap(board[empty_row][empty_col],board[empty_row-1][empty_col]);

				// empty_row is the row of the non-empty tile
				// after moving DOWN
				if (empty_row > goal_row(board[empty_row][empty_col]))
					++Manhattan_dist_sum;
				else --Manhattan_dist_sum;

				if (goal_row(board[empty_row][empty_col]) == empty_row)
					update_row_conflict(empty_row);
				else if (goal_row(board[empty_row][empty_col]) == empty_row-1)
					update_row_conflict(empty_row-1);

				--empty_row; return true;
			case LEFT:
				if (!empty_col) return false;
				swap(board[empty_row][empty_col],board[empty_row][empty_col-1]);

				// empty_col is the column of the non-empty tile
				// after moving RIGHT
				if (empty_col > goal_col(board[empty_row][empty_col]))
					++Manhattan_dist_sum;
				else --Manhattan_dist_sum;

				if (goal_col(board[empty_row][empty_col]) == empty_col)
					update_col_conflict(empty_col);
				else if (goal_col(board[empty_row][empty_col]) == empty_col-1)
					update_col_conflict(empty_col-1);

				--empty_col; return true;
			// default: exit(1);
		}
	}
	signed char heuristic() const{
		return Manhattan_dist_sum + (conflicts_sum << 1);
	}
};
signed char state::LIS_DP[4], state::LIS_length; // f**k

signed char moves_limit;
bool DLAstar(const state& st, const state::direction prev_dir = state::DNE){
	if (!st.heuristic()) return true;
	if (st.moves_spent + st.heuristic() > moves_limit) return false;

	state next_state = st; ++next_state.moves_spent;
	state tmp = next_state;
	// the purpose of this macro is merely to reduce code size
#define try_move(dir, inv_dir) {\
	if (prev_dir != state::inv_dir){\
		if (next_state.move(state::dir)){\
			if (DLAstar(next_state, state::dir)) return true;\
			next_state = tmp;\
		}\
	}\
}
	try_move(DOWN, UP)
	try_move(RIGHT, LEFT)
	try_move(UP, DOWN)
	try_move(LEFT, RIGHT)
	return false;
}
int main(){
	state st; // the default constructor reads input
	while (!DLAstar(st)) ++moves_limit;
	printf("%hhd\n", moves_limit); return 0;
}