#include<stdio.h>
#include<limits.h>
char direct[200010];
int place[200010];
int time=INT_MAX;	//第一次發生碰撞的時間

int main(void)
{
	int i;
	int n,haveans=0;
	
	scanf("%d",&n);
	scanf("%s",direct);
	for(i=0;i<n;i++)
		scanf("%d",&place[i]);
	
	for(i=0;i<n-1;i++)
	{
		if(direct[i]=='R' && direct[i+1]=='L'){	//只有RL的情形才有可能會發生碰撞
			//試著找出最短的時間
			if(time > (place[i+1]-place[i])/2 ){	//如果現在這一對的時間比time還小 
				time=(place[i+1]-place[i])/2;	//更新time 
				haveans=1;
			}
		}
	}
	if(!haveans){
		printf("-1\n");
	}else{
		printf("%d\n",time);
	}
	return 0;
}
