#include<bits/stdc++.h>
using namespace std;
class state{
public:
	int puzzle[4][4];
	int heuristic;
	int prevmove;
	int curmove;
	int ei,ej;
	
	state(int p[4][4]){
		int i,j;
		for(i=0;i<4;i++){
			for(j=0;j<4;j++){
				puzzle[i][j]=p[i][j];
			}
		}
		prevmove=ei=ej=-1;
		curmove=0;
		setheuristic();	//在抄陣列的時候就先算好它的heuristic
	}
	state(const state& s){
		int i,j;
		for(i=0;i<4;i++){
			for(j=0;j<4;j++){
				puzzle[i][j]=s.puzzle[i][j];
			}
		}
		heuristic=s.heuristic;
		prevmove=s.prevmove;
		curmove=s.curmove;
		ei=s.ei;
		ej=s.ej;
	}
	
	void setheuristic();
	void update(int i,int newi,int newj);	//與空白格交換並計算heuristic
	
	bool operator<(const state& rhs) const;
};
const int goalrow[16]={-1,0,0,0,0,1,1,1,1,2,2,2,2,3,3,3};
const int goalcol[16]={-1,0,1,2,3,0,1,2,3,0,1,2,3,0,1,2};

int main(){
	int i,j;
	int puzzle[4][4];
	for(i=0;i<4;i++){
		for(j=0;j<4;j++){
			scanf("%d",&puzzle[i][j]);
		}
	}

	state s(puzzle);
	for(i=0;i<4;i++){
		for(j=0;j<4;j++){
			if(!puzzle[i][j]){
				s.ei=i,s.ej=j;
				break;
			}
		}
	}
	
	
	const int di[4]={-1,1,0,0};
	const int dj[4]={0,0,1,-1};
	priority_queue<state> pq;
	pq.push(s);
	while(!pq.empty()){
		state now=pq.top();
		
		if(now.heuristic==0){
			printf("%d\n",now.curmove);
			break;
		}
		pq.pop();
		
		for(i=0;i<4;i++){
			int newi=now.ei+di[i];
			int newj=now.ej+dj[i];
			if(newi<0 || 3<newi || newj<0 || 3<newj){
				continue;
			}
			if(i == (now.prevmove^1)){
				continue;
			}
			
			state next=now;
			next.update(i,newi,newj);
			pq.push(next);
		}
	}
	
	if(pq.empty()){
		printf("-1\n");
	}
	return 0;
}
void state::setheuristic(){
	int i,j,k;
	int h=0;
	for(i=0;i<4;i++){
		for(j=0;j<4;j++){
			if(puzzle[i][j]){	//不是空格
				//manhattan distance
				int goali=goalrow[puzzle[i][j]];
				int goalj=goalcol[puzzle[i][j]];
				
				h+=abs(goali-i)+abs(goalj-j);
				
				//linear conflict
				if(i==goali){
					for(k=j;k<4;k++){
						if(puzzle[i][k]>0 && goalrow[puzzle[i][k]]==i && puzzle[i][j]>puzzle[i][k]){
							h+=2;
						}
					}
				}
				if(j==goalj){
					for(k=i;k<4;k++){
						if(puzzle[k][j]>0 && goalcol[puzzle[k][j]]==j && puzzle[i][j]>puzzle[k][j]){
							h+=2;
						}
					}
				}
			}
		}
	}
	heuristic=h;
}
void state::update(int i,int newi,int newj){
	prevmove=i;
	
	swap(puzzle[newi][newj],puzzle[ei][ej]);
	ei=newi,ej=newj;
	curmove++;
	
	setheuristic();
}
bool state::operator<(const state& rhs) const {
	return curmove+heuristic > rhs.curmove+rhs.heuristic;
}
