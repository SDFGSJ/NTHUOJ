/*https://www.geeksforgeeks.org/finding-shortest-path-between-any-two-nodes-using-floyd-warshall-algorithm/*/
#include<stdio.h>
#include<limits.h>
long long input[105][105];
long long w[105][105];
int Next[105][105];
int n;

void printpath(int,int);

int main(){
	int i,j,k;
	
	scanf("%d",&n);
	for(i=0;i<n;i++){
		for(j=0;j<n;j++){
			scanf("%d",&input[i][j]);
			Next[i][j]=j;	//將i到j這條path上的下一個點設為j
			if(i==j || input[i][j]==0){	//自己到自己 || i、j之間沒有路可以走
				input[i][j]=INT_MAX;
				Next[i][j]=INT_MAX;
			}
		}
	}
	
	//把input抄一份到w，之後再對w操作
	for(i=0;i<n;i++){
		for(j=0;j<n;j++){
			w[i][j]=input[i][j];
		}
	}
	
	for(k=0;k<n;k++){
		for(i=0;i<n;i++){
			for(j=0;j<n;j++){
				if(w[i][k] + w[k][j] <= w[i][j]){
					if(w[i][k] + w[k][j] < w[i][j]){	//如果這條路徑比較短就直接更新w跟Next
						w[i][j] = w[i][k] + w[k][j];
						Next[i][j]=Next[i][k];
					}else{	//如果路徑一樣長，就還要檢查字典序
						if(Next[i][k] < Next[i][j]){	//注意不能寫成k<Next[i][j]，會WA(6/10)
							Next[i][j]=Next[i][k];	//注意不能寫成Next[i][j]=k，會WA(6/10)
						}
					}
				}
			}
		}
	}

	for(i=0;i<n;i++){
		for(j=0;j<n;j++){
			if(i!=j && w[i][j]!=INT_MAX){	//不能自己走到自己 && i到j要有路可以走
				printf("Path(%d,%d):",i,j);		
				printpath(i,j);		
				printf("Difficulty:%d\n",w[i][j]);
			}
		}
	}
	
	for(i=0;i<n;i++){
		double central=0.0;
		for(j=0;j<n;j++){
			if(i!=j && w[j][i]!=INT_MAX){	//不能自己走到自己 && i到j要有路可以走
				central+=(1.0/w[j][i]);	//注意轉型
			}
		}
		printf("Centrality(%d):%.3f\n",i,central);
	}
	return 0;
}
void printpath(int start,int goal){
	int now=start;
	printf("%d",now);
	while(now!=goal){
		now=Next[now][goal];
		printf("->%d",now);
	}
	printf("\n");
}
