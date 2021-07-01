#include<stdio.h>
#include<string.h>
char str0[2048];
char str1[2048];
long long len[65];
char find(int,long long);
int main(void)
{
	int i,t,n;	//第n項
	long long m;	//第m個字(注意題目可能會給long long範圍的index) 
	scanf("%d",&t);
	while(t--)
	{
		scanf("%s%s",str0,str1);
		scanf("%d%lld",&n,&m);	//這邊的m記得scanf %lld
		len[0]=strlen(str0),len[1]=strlen(str1);
		for(i=2;i<60;i++){
			len[i]=len[i-1]+len[i-2];
		}
		/*for(i=0;i<60;i++){
			printf("%lld,",len[i]);
		}
		printf("\n");*/
		printf("%c\n",find(n,m));
	}
	return 0;
}
char find(int n,long long idx)	//第n項,第idx個字
{
	//basis step
	if(n==0){
		return str0[idx];
	}else if(n==1){
		return str1[idx];
	}
	//recursive step
	if(0<=idx && idx<len[n-2]){
		return find(n-2,idx);
	}else if(len[n-2]<=idx && idx<len[n]){
		return find(n-1,idx-len[n-2]);
	}
}
