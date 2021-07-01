#include<stdio.h>
#include<limits.h>
int input[105][105];
int Next[105][105];
int main(){
	int i,j,k;
	int n,t,q;
	scanf("%d",&t);
	for(int tc=1;tc<=t;tc++){
		scanf("%d",&n);
		scanf("%d",&q);
		
		for(i=0;i<n;i++){
			for(j=0;j<n;j++){
				scanf("%d",&input[i][j]);
				if(i==j || input[i][j]==0){	//自己到自己 || i、j之間沒有路可以走
					input[i][j]=1e7;
				}
			}
		}

		for(k=0;k<n;k++){
			for(i=0;i<n;i++){
				for(j=0;j<n;j++){
					if(input[i][k] + input[k][j] < input[i][j]){
						input[i][j] = input[i][k] + input[k][j];
					}
				}
			}
		}
		
		printf("Testcase%d\n",tc);
		for(i=0;i<q;i++){
			int from,to;
			scanf("%d%d",&from,&to);
			printf("Cost(%d,%d):",from,to);
			if(input[from][to]==1e7){
				printf("No Service\n");
			}else{
				printf("%d\n",input[from][to]);
			}
		}
	}
	return 0;
}
