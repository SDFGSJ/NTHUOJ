#include<stdio.h>
#include<limits.h>
#include<math.h>
int h[25+5];
int route[25]={1};
int min_energy=INT_MAX;
int min_jumps=INT_MAX;

int cost(int jumps);
void jump(int cur,int end,int step);

int main(void)
{
	int n;
	int i;
	scanf("%d",&n);
	
	for(i=1;i<=n;i++){
		scanf("%d",&h[i]);
	}
	
	jump(1,n,1);
	
	printf("%d %d\n",min_energy,min_jumps);
	
	/*for(i=0;i<n;i++){
		printf("%d,",h[i]);
	}*/
	return 0;
}
int cost(int jumps)
{
	int i;
	int total_energy=0;
	for(i=0;i<jumps;i++){
		total_energy+=abs( h[ route[i] ]-h[ route[i+1] ] );
	}
	return total_energy;
}
void jump(int cur,int end,int step)
{
	//basic step
	if(cur>=end){
		if(cur==end){	//we found a path
			int cur_energy=0;
			cur_energy=cost(step-1);
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
	int i;
	for(i=1;i<=2;i++)
	{
		route[step]=cur+i;
		jump(cur+i,end,step+1);
	}
}
