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
		yleap=isleap(y);	//�ˬd�}�l�~���S���| 
		for(i=y+1;;i++)	//�q�U�@�~�}�l�ˬd�_
		{
			leap=0;	//�@�}�l�����]�D�|�~ 
			if(isleap(i)){	//�ˬd�o�~���S���| 
				leap=1;
				sum+=2;
			}else{
				sum+=1;
			}
			sum%=7;
			if(!sum && yleap==leap){	//�p�Gsum%7==0 && �o�@�~���J���~���P���|�Υ��~�N�����j�� 
				break;
			}
		}
		printf("%d\n",i);
	}
	return 0;
}
