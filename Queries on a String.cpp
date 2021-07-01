#include<stdio.h>
char str[10010];
int l,r,k;
void right_shift(void);

int main(void)
{
	int i,j;
	int query,len;
	scanf("%s",str);
	scanf("%d",&query);
	for(i=0;i<query;i++)
	{
		scanf("%d%d%d",&l,&r,&k);
		l-=1,r-=1;	//先將l,r處理成array index 
		len=r-l+1;	//取得字串長度 
		k%=len;	//看要搬幾個字 
		for(j=0;j<k;j++)
		{
			right_shift();
		}
	}
	printf("%s\n",str);
	return 0;
}
void right_shift(void)
{
	int i;
	char temp=str[r];	//先將最後一個字str[r]記起來 
	for(i=r;i>l;i--)
		str[i]=str[i-1];	//右移
	str[l]=temp;	//最後再填上第一個字str[l] 
}
