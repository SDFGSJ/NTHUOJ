#include<stdio.h>
int main(void)
{
	//prime儲存質數，power儲存次方 
	int prime[100]={0},power[100]={0}; 
	int num,flag=0,index=0;
	//i,j迴圈變數 
	int i,j;
	scanf("%d",&num);
	
	//build a prime array from 2 to num
	for(i=2;i<=num;i++){
		//每次開始前都要將flag設成0
		flag=0;
		for(j=2;j*j<=i;j++){
			if(i%j==0){
				//如果它能被整除則它不是質數 
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
	//printf("\n做完prime array後的index=%d\n",index);
	
	//開始計算次方數 
	for(i=2;i<=num;i++){
		//因為會對i做更動，所以就要設一個變數t_i記住i的值 
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
	
	//最後把power+1做相乘 
	unsigned long long ans=1;
	for(i=0;i<index;i++){
		ans*=(power[i]+1);
	}
	printf("%lld",ans);
	
	return 0;
}
