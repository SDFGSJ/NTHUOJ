#include<stdio.h>
#include<stdbool.h>

char s[510],p[510];
bool dp[510][510];

void solve(int i,int j){
	if(dp[i][j])
		return;
	
	dp[i][j]=true;

	if(p[j]=='\0')
  		return;

	if(p[j+1]=='*'){
		solve(i,j+2);
		int idx=i;
		while(s[idx]!='\0' && (s[idx]==p[j] || p[j]=='.') ){
		  solve(idx+1,j+2);
		  idx++;
		}
	}
	
	if(s[i]!='\0' && (s[i]==p[j] || p[j]=='.') ){
		solve(i+1,j+1);
	}
}

int main(void)
{
	int q;
	scanf("%s%s",s,p);
	solve(0,0);
	scanf("%d",&q);
	while(q--)
	{
		int qS,qP;
		scanf("%d%d",&qS,&qP);
		if(dp[qS][qP]){
			printf("True\n");
		}else{
			printf("False\n");
		}
	}
	return 0;
}
