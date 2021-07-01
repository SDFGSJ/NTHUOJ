#include<bits/stdc++.h>
using namespace std;
class Board {
	public:
		Board() {}
		Board(int* initVal) {
			step = 0;
			for(int i=0;i<8;i++)
				val[i] = initVal[i];
		}
		void move() {	//順時鐘轉一圈
			step++;
			for(int i=0;i<7;i++)
				swap(val[i], val[7]);
		}
		void adjSwap(int i) {	//跟旁邊的交換
			step++;
			swap(val[i], val[(i + 1) % 8]);
		}
		void oppSwap(int i) {	//跟對面的交換
			step++;
			swap(val[i], val[(i + 4) % 8]);
		}
		int getStep(){
			return step;
		}
		bool operator < (const Board &a)const{	//因為要讓set知道如何排序
			for(int i=0;i<8;i++)
				if(val[i] != a.val[i])
					return val[i] < a.val[i];
			return false;
		}
		bool operator == (const Board &a)const{
			for(int i=0;i<8;i++)
				if(val[i] != a.val[i])
					return false;
			return true;
		}
	private:
		int step, val[8];
};

queue<Board> q;
set<Board> visBoard;

void updateState(Board& nextBoard, const Board& boardB, int& ans) {	//會把board push到queue裡
	if(nextBoard == boardB) {
		ans = nextBoard.getStep();	//ans是外部的變數
		return;	//如果有答案就不需要push到queue裡
	}
	if(visBoard.count(nextBoard) == 1)	//如果這個state已經出現過
		return;
	q.push(nextBoard);
	visBoard.insert(nextBoard);
}

int main() {
	int t;
	cin >> t;
	while(t--) {
		Board boardA,boardB;
		for(int i=0;i<2;i++) {
			int initval[8];
			for(int j : {0, 1, 2, 7, 3, 6, 5, 4})
				cin >> initval[j];
			if(i==0){
				boardA=Board(initval);
			}else{
				boardB=Board(initval);
			}
		}

		int ans = -1;
		if(boardA == boardB)
			ans = 0;
		else {
			q.push(boardA);
			visBoard.insert(boardA);

			while(!q.empty() && ans == -1) {
				Board now = q.front();
				q.pop();
				
				Board nextBoard;
				
				//順時針
				nextBoard = now;
				nextBoard.move();
				updateState(nextBoard, boardB, ans);
				
				//跟旁邊交換
				for(int i=0;i < 8 && ans == -1;i++) {
					nextBoard = now;
					nextBoard.adjSwap(i);
					updateState(nextBoard, boardB, ans);
				}
				
				//跟對面交換
				for(int i=0;i < 4 && ans == -1;i++) {
					nextBoard = now;
					nextBoard.oppSwap(i);
					updateState(nextBoard, boardB, ans);
				}
			}
		}
		cout << ans << "\n";
	}
	return 0;
}
