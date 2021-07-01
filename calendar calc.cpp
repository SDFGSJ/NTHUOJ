#include<stdio.h>
int main(void)
{
	int month,day,i,sum=0;
	int a[12]={0,31,29,31,30,31,30,31,31,30,31,30};
	char ch;
	scanf("%d%c%d",&month,&ch,&day);
	for(i=0;i<month;i++)
	{
		sum+=a[i];
	}
	printf("%d\n",sum+day);
	return 0;
}
