#include<stdio.h>
int main(void)
{	
	/*
	size:�@�}�l��J����
	count:�q1�}�l�̧Ƕ�J�C�@��
	m��Cn����
	i,j:�j���ܼ� 
	*/
	int size,count=1,m=0,n=0,i,j;
	scanf("%d",&size);
	int map[2*size][2*size]={0};
	
	//size���h�j�A�~�h�j��N�n�]size�� 
	for(i=1;i<size+1;i++)
	{
		//���k 
		while(n<2*size-i)
		{
			map[m][n]=count;
			count++;//count�O�o��s 
			n++;//n�O�o��s 
		}
		//���U 
		while(m<2*size-i)
		{
			map[m][n]=count;
			count++;
			m++;
		}
		//���� 
		while(n>i-1)
		{
			map[m][n]=count;
			count++;
			n--;
		}
		//���W 
		while(m>i-1)
		{
			map[m][n]=count;
			count++;
			m--;
		}
		m++;/*�]���C�����@���N�|�����~���Ʀr�A�ҥHm,n���n�[1*/
		n++;
	}
		
	/*�L�X��*/
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
