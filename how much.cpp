//«ÝÀu¤Æ 
#include<stdio.h>
int dish[1000000]={0};
int check[32]={0};
int main(void)
{
	int num,query,kind;
	int l,r;
	int i,j;
	scanf("%d%d",&num,&query);
	
	for(i=0;i<num;i++){
		scanf("%d",&dish[i]);
	}
	
	for(i=0;i<query;i++){
		kind=0;
		for(j=0;j<=31;j++){
			check[j]=0;
		}
		
		scanf("%d%d",&l,&r);
		for(j=l;j<=r;j++){
			if(check[ dish[j] ]==0){
				check[ dish[j] ]=1;
				kind++;
			}		
		}
		printf("%d\n",kind);			
	}
	return 0;
}
