#include<stdio.h>
int main(void)
{
	int num,temp,a[5]={0},index=0;
	scanf("%d",&num);
	temp=num;//因為之後的num在while迴圈會改變，所以用temp把num記起來 
	while(num!=0)
	{
		a[index]=num%10;
		num/=10;
		index++;
	}
	//printf("num=%d\n",temp);
	/*for(int i=0;i<5;i++)
		printf("%d ",a[i]);*/
	if(index%2==0)//如果是0,2,4位數 
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
	else//如果是1,3,5位數
	{
		if(index==1)//1位數一定是palindrome 
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
	//printf("此為%d位數",index);
	return 0;
}
