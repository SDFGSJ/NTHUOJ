#include<stdio.h>
int main(void)
{
	//prime�x�s��ơApower�x�s���� 
	int prime[100]={0},power[100]={0}; 
	int num,flag=0,index=0;
	//i,j�j���ܼ� 
	int i,j;
	scanf("%d",&num);
	
	//build a prime array from 2 to num
	for(i=2;i<=num;i++){
		//�C���}�l�e���n�Nflag�]��0
		flag=0;
		for(j=2;j*j<=i;j++){
			if(i%j==0){
				//�p�G����Q�㰣�h�����O��� 
				flag=1;
				break;
			}
		}
		if(!flag){
			//printf("%d ",i);
			prime[index]=i;
			index++;
		}
	}	
	//printf("\n����prime array�᪺index=%d\n",index);
	
	//�}�l�p�⦸��� 
	for(i=2;i<=num;i++){
		//�]���|��i����ʡA�ҥH�N�n�]�@���ܼ�t_i�O��i���� 
		int t_i=i;
		for(j=0;j<index;j++){
			while(t_i%prime[j]==0){
				power[j]++;
				t_i=t_i/prime[j];
			}
		}
	}
	
	/*printf("power[]:");
	for(i=0;i<index;i++){
		printf("%d ",power[i]);
	}*/
	
	//�̫��power+1���ۭ� 
	unsigned long long ans=1;
	for(i=0;i<index;i++){
		ans*=(power[i]+1);
	}
	printf("%lld",ans);
	
	return 0;
}
