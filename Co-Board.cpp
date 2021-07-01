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
		void move() {	//��������@��
			step++;
			for(int i=0;i<7;i++)
				swap(val[i], val[7]);
		}
		void adjSwap(int i) {	//����䪺�洫
			step++;
			swap(val[i], val[(i + 1) % 8]);
		}
		void oppSwap(int i) {	//��ﭱ���洫
			step++;
			swap(val[i], val[(i + 4) % 8]);
		}
		int getStep(){
			return step;
		}
		bool operator < (const Board &a)const{	//�]���n��set���D�p��Ƨ�
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

void updateState(Board& nextBoard, const Board& boardB, int& ans) {	//�|��board push��queue��
	if(nextBoard == boardB) {
		ans = nextBoard.getStep();	//ans�O�~�����ܼ�
		return;	//�p�G�����״N���ݭnpush��queue��
	}
	if(visBoard.count(nextBoard) == 1)	//�p�G�o��state�w�g�X�{�L
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
				
				//���ɰw
				nextBoard = now;
				nextBoard.move();
				updateState(nextBoard, boardB, ans);
				
				//�����洫
				for(int i=0;i < 8 && ans == -1;i++) {
					nextBoard = now;
					nextBoard.adjSwap(i);
					updateState(nextBoard, boardB, ans);
				}
				
				//��ﭱ�洫
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
