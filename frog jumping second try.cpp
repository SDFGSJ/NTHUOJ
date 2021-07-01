#include<stdio.h>
#include<limits.h>
#include<math.h>
int h[25+1];
int route[25+1]={1};
int min_energy=INT_MAX,min_jumps=INT_MAX;
int cur_energy=0;


void jump(int cur,int end,int step);
int cost(int step);
int main(void)
{
	int n;
	int i,j;
	
	scanf("%d",&n);
	for(i=1;i<=n;i++){
		scanf("%d",&h[i]);
	}
	
	jump(1,n,1);
	/*printf("h[]=");
	for(i=0;i<10;i++)	printf("%d,",h[i]);
	printf("\nroute[]=");
	for(i=0;i<10;i++)	printf("%d,",route[i]);*/
	
	printf("%d %d\n",min_energy,min_jumps);
	return 0;
}
void jump(int cur,int end,int step)
{
	int i;
	
	//basic step
	if(cur>=end)
	{
		if(cur==end)	//found a path
		{
			int cur_energy=cost(step-1);
			if(cur_energy<min_energy){
				min_energy=cur_energy;
				min_jumps=step-1;
			}else if(cur_energy==min_energy && step-1<min_jumps){
				min_jumps=step-1;
			}
		}
		return;
	}
	
	//recursive step
	for(i=1;i<=2;i++){
		route[step]=cur+i;
		jump(cur+i,end,step+1);
	}
}
int cost(int step)
{
	int i;
	cur_energy=0;
	for(i=0;i<step;i++)
	{
		cur_energy+=abs(h[ route[i] ]-h[ route[i+1] ]);
	}
	return cur_energy;
}
