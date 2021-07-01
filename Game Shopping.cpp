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
		if(used[idx]!=1){	//如果目前的bill沒有用過 
			if(bill[idx]>=game[i]){	//如果目前的bill > game的價錢就買下來 
				used[idx]=1;	//將這個bill標記為用過 
				count++;	//購買的game數量+1 
				idx++;	//移至下一個game
			}
		}
	}
	/*for(i=0;i<m;i++){
		printf("%d,",used[i]);
	}*/
	printf("%d\n",count);
	return 0;
}
