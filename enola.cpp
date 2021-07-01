#include<stdio.h>
int main(void)
{
	int n,m,i,rec_a[26]={0},rec_b[26]={0},flag=0;
	char a[1005],b[1005];
	while( scanf("%d",&n)!=EOF )
	{
		
		scanf("%d%s%s",&m,a,b);	
		if(n!=m)
			printf("NO\n");
		else{
			flag=0;
			for(i=0;i<26;i++){
				rec_a[i]=0;rec_b[i]=0;
			}
			for(i=0;i<n;i++){
				rec_a[a[i]-'a']++;
				rec_b[b[i]-'a']++;
			}
			for(i=0;i<26;i++){
				if(rec_a[i]!=rec_b[i]){
					flag=1;//代表有不同的地方 
					break;
				}
			}
			if(!flag){
				printf("YES\n");
			}else{
				printf("NO\n");
			}		
		}	
	}
	return 0;	
} 
