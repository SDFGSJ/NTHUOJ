#include<stdio.h>
int main(void)
{	
	/*
	size:一開始輸入的值
	count:從1開始依序填入每一格
	m橫列n直行
	i,j:迴圈變數 
	*/
	int size,count=1,m=0,n=0,i,j;
	scanf("%d",&size);
	int map[2*size][2*size]={0};
	
	//size有多大，外層迴圈就要跑size次 
	for(i=1;i<size+1;i++)
	{
		//往右 
		while(n<2*size-i)
		{
			map[m][n]=count;
			count++;//count記得更新 
			n++;//n記得更新 
		}
		//往下 
		while(m<2*size-i)
		{
			map[m][n]=count;
			count++;
			m++;
		}
		//往左 
		while(n>i-1)
		{
			map[m][n]=count;
			count++;
			n--;
		}
		//往上 
		while(m>i-1)
		{
			map[m][n]=count;
			count++;
			m--;
		}
		m++;/*因為每做完一輪就會往內繼續填數字，所以m,n都要加1*/
		n++;
	}
		
	/*印出來*/
	for(i=0;i<2*size-1;i++){
		for(j=0;j<2*size;j++){
			printf("%d ",map[i][j]);
		}
		printf("\n");
	}
	for(i=0;i<2*size-1;i++)
	{
		printf("%d ",map[2*size-1][i]);
	}
	printf("%d",map[2*size-1][2*size-1]);		
	return 0;
}
