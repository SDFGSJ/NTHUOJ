#include<stdio.h>
#include<limits.h>
int value[15];
int weight[15];
int ans=INT_MAX,n,k;

void getval(int,int,int);
int min(int a,int b){
	if(a>b)	return b;
	else return a;
}
int main(void)
{
	int i;
	scanf("%d%d",&n,&k);
	for(i=0;i<n;i++){
		scanf("%d%d",&value[i],&weight[i]);
	}
	getval(-1,0,0);
	printf("%d\n",ans);
	return 0;
}
void getval(int idx,int val,int w)
{
	if(idx>=n)
		return;
	else{
		if(val>=k && w<ans){
			ans=w;
		}
		
		getval(idx+1,val+value[idx+1],w+weight[idx+1]);	//choose
		getval(idx+1,val,w);	//don't choose

	}
}
