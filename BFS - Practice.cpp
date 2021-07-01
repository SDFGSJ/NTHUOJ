#include<bits/stdc++.h>
using namespace std;
char board[100010];
int visited[100010];
int dist[100010];
int di[4]={-1,0,1,0};
int dj[4]={0,1,0,-1};

queue<pair<int,int>> q;
int main(){
	int i,j;
	int n,m;
	int si,sj,ei,ej;	//start,end i,j
	int ans=-1;
	
	scanf("%d%d",&n,&m);
	getchar();
	for(i=0;i<n;i++){
		for(j=0;j<m;j++){
			scanf("%c",&board[i*m+j]);
		}
		getchar();
	}

	scanf("%d%d%d%d",&si,&sj,&ei,&ej);
	si--,sj--,ei--,ej--;
	
	q.push({si,sj});
	visited[si*m+sj]=1;
	dist[si*m+sj]=0;	//將起始位置的距離設為0
	while(!q.empty()){
		auto now=q.front();
		q.pop();
		//printf("(%d,%d)\n",now.first,now.second);
		if(now.first==ei && now.second==ej){
			ans=dist[now.first*m+now.second];
			break;
		}
		for(i=0;i<4;i++){
			int now_i=now.first+di[i];
			int now_j=now.second+dj[i];
			int idx=now_i*m+now_j;
			if(0<=now_i && now_i<n && 0<=now_j && now_j<m && board[idx]=='0' && !visited[idx]){
				dist[idx] = dist[now.first*m+now.second] + 1;
				q.push({now_i,now_j});
				visited[idx]=1;
			}
		}
	}
	/*printf("dist[]=\n");
	for(i=0;i<n;i++){
		for(j=0;j<m;j++){
			printf("%d,",dist[i*m+j]);
		}
		printf("\n");
	}*/
	printf("%d\n",ans);
	return 0;
}
