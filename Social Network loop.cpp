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
			Next[i][j]=j;	//�Ni��j�o��path�W���U�@���I�]��j
			if(i==j || input[i][j]==0){	//�ۤv��ۤv || i�Bj�����S�����i�H��
				input[i][j]=INT_MAX;
				Next[i][j]=INT_MAX;
			}
		}
	}
	
	//��input�ۤ@����w�A����A��w�ާ@
	for(i=0;i<n;i++){
		for(j=0;j<n;j++){
			w[i][j]=input[i][j];
		}
	}
	
	for(k=0;k<n;k++){
		for(i=0;i<n;i++){
			for(j=0;j<n;j++){
				if(w[i][k] + w[k][j] <= w[i][j]){
					if(w[i][k] + w[k][j] < w[i][j]){	//�p�G�o�����|����u�N������sw��Next
						w[i][j] = w[i][k] + w[k][j];
						Next[i][j]=Next[i][k];
					}else{	//�p�G���|�@�˪��A�N�٭n�ˬd�r���
						if(Next[i][k] < Next[i][j]){	//�`�N����g��k<Next[i][j]�A�|WA(6/10)
							Next[i][j]=Next[i][k];	//�`�N����g��Next[i][j]=k�A�|WA(6/10)
						}
					}
				}
			}
		}
	}

	for(i=0;i<n;i++){
		for(j=0;j<n;j++){
			if(i!=j && w[i][j]!=INT_MAX){	//����ۤv����ۤv && i��j�n�����i�H��
				printf("Path(%d,%d):",i,j);		
				printpath(i,j);		
				printf("Difficulty:%d\n",w[i][j]);
			}
		}
	}
	
	for(i=0;i<n;i++){
		double central=0.0;
		for(j=0;j<n;j++){
			if(i!=j && w[j][i]!=INT_MAX){	//����ۤv����ۤv && i��j�n�����i�H��
				central+=(1.0/w[j][i]);	//�`�N�૬
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
