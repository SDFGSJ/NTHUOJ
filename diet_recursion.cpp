#include<stdio.h>
int ok=0,n,total;
int c[30];

void diet(int,int);

int main(void)
{
	int i;
	
	scanf("%d%d",&n,&total);
	for(i=0;i<n;i++){
		scanf("%d",&c[i]);
	}
	
	diet(0,0);
	
	if(ok)
		printf("YES\n");
	else
		printf("NO\n");
	
	return 0;
}
void diet(int sum,int count)
{
	if(sum==total){
		ok=1;
	}else if(count<=n){		//���S��'='���G�S�t 
		/*
		����bubble sort�A�S�����[ 
		for(int i=count;i<n;i++){
			//printf("sum=%d,count=%d\n",sum,count);
			diet(sum+c[i],i+1);
		}
		*/
		
		//�𪬹Ϥ�����[�@�� 
		diet(sum,count+1);	//���� 
		diet(sum+c[count],count+1);	//�� 
	}
}
