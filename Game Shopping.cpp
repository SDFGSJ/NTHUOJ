#include<stdio.h>
int game[1010];
int bill[1010];
int used[1010];
int main(void)
{
	int i;
	int n,m;
	int idx=0,count=0;
	
	scanf("%d%d",&n,&m);
	for(i=0;i<n;i++)
		scanf("%d",&game[i]);
	for(i=0;i<m;i++)
		scanf("%d",&bill[i]);
	
	for(i=0;i<n;i++)
	{
		if(used[idx]!=1){	//�p�G�ثe��bill�S���ιL 
			if(bill[idx]>=game[i]){	//�p�G�ثe��bill > game�������N�R�U�� 
				used[idx]=1;	//�N�o��bill�аO���ιL 
				count++;	//�ʶR��game�ƶq+1 
				idx++;	//���ܤU�@��game
			}
		}
	}
	/*for(i=0;i<m;i++){
		printf("%d,",used[i]);
	}*/
	printf("%d\n",count);
	return 0;
}
