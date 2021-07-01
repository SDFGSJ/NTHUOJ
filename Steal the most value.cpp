#include<stdio.h>
int value[1005];
int weight[1005];
int dp[1005][1005];
int max(int a,int b){
	if(a>b)	return a;
	else	return b;
}
int main(void)
{
	int i,j;
	int num,capa;
	scanf("%d%d",&num,&capa);
	for(i=0;i<num;i++){
		scanf("%d%d",&value[i],&weight[i]);
	}
	
	for(i=0;i<num;i++){
		for(j=0;j<=capa;j++){
			if(j<weight[i]){
				dp[i+1][j]=dp[i][j];
			}else{
				dp[i+1][j]=max(dp[i][j],dp[i][j-weight[i]]+value[i]);
			}
		}
	}
	/*for(i=0;i<=num;i++){
		for(j=0;j<=capa;j++){
			printf("%d,",dp[i][j]);
		}
		printf("\n");
	}*/
	printf("%d\n",dp[num][capa]);
	return 0;
}
