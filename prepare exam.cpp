#include<stdio.h>
int x[100000],y[100000];
int main(void)
{
	int n,i,j,ans=1;
	//combi[100][100] is a pascal triangle
	long int combi[101][101]={0};
	
	scanf("%d",&n);
	for(i=0;i<n;i++)
		scanf("%d",&x[i]);
	for(i=0;i<n;i++)
		scanf("%d",&y[i]);
		
	//build a pascal 
	for(i=0;i<101;i++){
		for(j=0;j<=i;j++){
			if(j==0||i==j)
				combi[i][j]=1;
			else
				combi[i][j]=(combi[i-1][j-1]+combi[i-1][j])%10007;
		}
	}

	for(i=0;i<n;i++){
		ans=(ans*combi[x[i]][y[i]])%10007;
	} 
	printf("%d\n",ans);
	
	return 0;
}
