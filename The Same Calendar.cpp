#include<stdio.h>
int isleap(int y)
{
	return y%400==0 || (y%4==0 && y%100!=0);
}
int main(void)
{
	int i;
	int T;
	int y,yleap=0,leap=0,sum=0;
	scanf("%d",&T);
	while(T--)
	{
		sum=0;
		scanf("%d",&y);
		yleap=isleap(y);	//檢查開始年有沒有閏 
		for(i=y+1;;i++)	//從下一年開始檢查起
		{
			leap=0;	//一開始都假設非閏年 
			if(isleap(i)){	//檢查這年有沒有閏 
				leap=1;
				sum+=2;
			}else{
				sum+=1;
			}
			sum%=7;
			if(!sum && yleap==leap){	//如果sum%7==0 && 這一年跟輸入的年份同為閏或平年就跳離迴圈 
				break;
			}
		}
		printf("%d\n",i);
	}
	return 0;
}
