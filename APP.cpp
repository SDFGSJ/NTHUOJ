#include<stdio.h>
#include<limits.h>
char str[1010];
int dp[1010][1010];
int check(int l,int r);
int main(void)
{
	int len,num,ans;
	int i,j;
	scanf("%d%d%s",&len,&num,str);
	//這裡不能用memset因為memset是專門給字串用的不是int 
	for(i=0;i<len;i++){
		for(j=0;j<len;j++){
			dp[i][j]=INT_MAX;
		}
	}
	ans=check(0,len-1);
	//printf("ans=%d\n",ans);
	if(ans<=num){
		printf("Yes\n");
	}else{
		printf("No\n");
	}
	return 0;
}
int check(int l,int r)
{
	int delete_l;
	int delete_r;
	//basis step
	if(l>=r){
		dp[l][r]=0;
		return dp[l][r];
	}
	//recursive step
	if(str[l]==str[r]){
		dp[l][r]=check(l+1,r-1);
		return dp[l][r];
	}else{
		if(dp[l][r]==INT_MAX){
			delete_l=check(l+1,r);
			delete_r=check(l,r-1);
			if(delete_l>delete_r){	//選小的，因為字數越少越好 
				dp[l][r]=delete_r+1;
			}else{
				dp[l][r]=delete_l+1;
			}
			return dp[l][r];
		}else{
			return dp[l][r];
		}
	}
}
