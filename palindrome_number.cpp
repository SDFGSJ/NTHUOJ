#include<stdio.h>
int main(void)
{
	int num,temp,a[5]={0},index=0;
	scanf("%d",&num);
	temp=num;//�]�����᪺num�bwhile�j��|���ܡA�ҥH��temp��num�O�_�� 
	while(num!=0)
	{
		a[index]=num%10;
		num/=10;
		index++;
	}
	//printf("num=%d\n",temp);
	/*for(int i=0;i<5;i++)
		printf("%d ",a[i]);*/
	if(index%2==0)//�p�G�O0,2,4��� 
	{
		if(index==2){
			if(temp==a[0]*10+a[1])
				printf("Yes\n");
			else
				printf("No\n");
		}else if(index==4){
			if(temp==a[0]*1000+a[1]*100+a[2]*10+a[3])
				printf("Yes\n");
			else
				printf("No\n");
		}else
			printf("Yes\n");	
	}
	else//�p�G�O1,3,5���
	{
		if(index==1)//1��Ƥ@�w�Opalindrome 
			printf("Yes\n");
		else if(index==3){
			if(temp==a[0]*100+a[1]*10+a[2])
				printf("Yes\n");
			else
				printf("No\n");
		}else if(index==5){
			if(temp==a[0]*10000+a[1]*1000+a[2]*100+a[3]*10+a[4])
				printf("Yes\n");
			else
				printf("No\n");
		}		
	}
	//printf("����%d���",index);
	return 0;
}
