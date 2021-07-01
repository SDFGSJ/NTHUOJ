#include<stdio.h>
long long len[55];
char find(int n,long long idx);
int main(void)
{
	int i;
	int k,l,r;
	while(~scanf("%d%d%d",&k,&l,&r))
	{
		len[1]=3;	//index最好從1開始，用0怕不直觀從而造成bug 
		for(i=2;i<=k;i++)
			len[i]=2*len[i-1]+3;
			
		for(i=l;i<=r;i++){
			printf("%c",find(k,i));
		}
		printf("\n");
	}
	return 0;
}
char find(int n,long long idx)
{
	if(idx==0){
		return 'O';
	}else if(idx==len[n-1]+1){
		return 'u';
	}else if(idx==len[n]-1){	//最後一個字 
		return 'Q';
	}else if(1<=idx && idx<=len[n-1]){
		return find(n-1,idx-1);	//回去上一個找 
	}else if(1+len[n-1]+1<=idx && idx<len[n]-1){
		return find(n-1,idx-len[n-1]-2);	//回去上一個找 
	}
}
