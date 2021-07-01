#include<stdio.h>
int main(void)
{
	int n,m;
	int i;
	char a[1010],b[1010];
	int a_rec[26]={0},b_rec[26]={0};
	
	while( scanf("%d%d%s%s",&n,&m,a,b)!=EOF )
	{
		int flag=0;
		
		for(i=0;i<26;i++){
			a_rec[i]=0;
			b_rec[i]=0;
		}
		
		for(i=0;i<n;i++){
			a_rec[ a[i]-'a' ]++;
		}
		
		for(i=0;i<m;i++){
			b_rec[ b[i]-'a' ]++;
		}
		
		for(i=0;i<26;i++){
			if(a_rec[i]!=b_rec[i]){
				flag=1;
				break;
			}
		}
		
		if(flag){
			printf("NO\n");
		}else{
			printf("YES\n");
		}
	}
	return 0;
}
