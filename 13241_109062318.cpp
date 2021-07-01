#include<bits/stdc++.h>
using namespace std;
class Seq {
	public:
		Seq() {step=0;}
		Seq(int* initVal) {
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
		int getStep(){
			return step;
		}
		void printseq(){
			int i;
			for(i=0;i<8;i++){
				printf("%d,",val[i]);
			}
			printf("\n");
		}
		bool operator < (const Seq &a)const{	//�]���n��set���D�p��Ƨ�
			for(int i=0;i<8;i++)
				if(val[i] != a.val[i])
					return val[i] < a.val[i];
			return false;
		}
		bool operator == (const Seq &a)const{
			for(int i=0;i<8;i++)
				if(val[i] != a.val[i])
					return false;
			return true;
		}
	private:
		int step, val[8];
};

queue<Seq> q;
set<Seq> visseq;

void updateState(Seq& nextseq, const Seq& seqB, int& ans) {	//�|��board push��queue��
	if(nextseq == seqB) {
		ans = nextseq.getStep();	//ans�O�~�����ܼ�
		return;	//�p�G�����״N���ݭnpush��queue��
	}
	if(visseq.count(nextseq) == 1)	//�p�G�o��state�w�g�X�{�L
		return;
	q.push(nextseq);
	visseq.insert(nextseq);
}

int main() {
	int t;
	cin >> t;
	while(t--) {
		int ans = -1;
		while(!q.empty()){
			q.pop();
		}
		Seq seqA,seqB;
		for(int i=0;i<2;i++) {
			int initval[8];
			for(int j=0;j<8;j++)
				cin >> initval[j];
			if(i==0){
				seqA=Seq(initval);
			}else{
				seqB=Seq(initval);
			}
		}
		
		/*printf("seqa[]=");
		seqA.printseq();
		printf("seqb[]=");
		seqB.printseq();*/
		
		
		if(seqA == seqB)
			ans = 0;
		else {
			q.push(seqA);
			visseq.insert(seqA);

			while(!q.empty() && ans == -1) {
				Seq now = q.front();
				q.pop();
				
				//now.printseq();
				
				Seq nextseq;
				
				//���ɰw
				nextseq = now;
				/*printf("after assign\n");
				nextseq.printseq();*/
				nextseq.move();
				/*printf("after move\n");
				nextseq.printseq();*/
				updateState(nextseq, seqB, ans);
				
				//�����洫
				for(int i=0;i < 8 && ans == -1;i++) {
					nextseq = now;
					nextseq.adjSwap(i);
					updateState(nextseq, seqB, ans);
				}
			}
		}
		cout << ans << "\n";
	}
	return 0;
}
