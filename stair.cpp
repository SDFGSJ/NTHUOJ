#include<stdio.h>
int main(void)
{
	int n,i;//n stairs,loop variable i
	long long stair[120]={0};//р–顶┮Τǐ猭计常硂柑 
	int a115[20]={0},a113[20]={0};//рㄢ计计int皚柑 
	int ans[25]={0};//秈︽羆よ 
	
	scanf("%d",&n);
	for(i=0;i<n;i++){
		if(i<3)
			stair[i]=1;//i=1,2 --> base case
		else
			stair[i]=stair[i-1]+stair[i-3];	
	}

	int count=0;
	if(n<3)
		printf("1\n");
		
	else if(3<=n && n<=115)
		printf("%lld\n",stair[n-1]+stair[n-3]);	
		
	else{
		//计计
		while(stair[115]!=0 && stair[113]!=0){
			a115[count]=stair[115]%10;			
			stair[115]/=10;
			//printf("%d",a115[count]);
			a113[count]=stair[113]%10;						
			stair[113]/=10;
			//printf("%d",a113[count]);
			count++;
		}
		
		/*printf("a115[]=");
		for(i=0;i<20;i++){
			printf("%d ",a115[i]);
		}
		printf("\na113[]=");
		for(i=0;i<20;i++){
			printf("%d ",a113[i]);
		}
		printf("\ncount=%d\n",count);*/
		
		//秈︽猭
		for(i=0;i<=count;i++){
			if(a115[i]+a113[i]>=10){//狦穦秈 
				ans[i]=a115[i]+a113[i]-10;
				a115[i+1]++;//ê秈1繦獽メ倒a113 or a115 
			}else{
				ans[i]=a115[i]+a113[i];
			}
		}
		//print out the answer
		for(i=19;i>=0;i--){
			printf("%d",ans[i]);
		}
		
		printf("\n");
	}
	return 0;
}
