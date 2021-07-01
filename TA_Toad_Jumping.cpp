#include<stdio.h>
#include<math.h>

int n,s,t;
int max_energy = -1;	// The maximum energy in the current path
int max_jumps = -1;		// The maximum jumps in the current path
int color[20];			// The color of each stone
int height[20];			// The height of each stone
int route[20];			// The route of each step
int havejumped[20]={0}; // To record whether the stone is jumped or not.

int cost(int jumps)
{
    int energy=0;
    for(int i=0;i<jumps;i++)
        energy += abs(route[i]-route[i+1]) * abs(height[ route[i] ]-height[ route[i+1] ]);
    return energy;
}
int valid(int cur,int next)
{
	if(havejumped[next]==1)	//The stone is jumped.
		return 0;
	if(next<1 || next>n)	//The index is out of range
		return 0;
	if(abs(next-cur)==1)	//For stonei-1 and i+1 
		return 1;
	if(color[cur]==color[next])	//For stone with the same color
		return 1;
	
	return 0;
}
void jump(int cur,int step)
{
    if(cur==t)	//�p�G�{�b������I 
    {
        int cur_energy=cost(step-1);
        if(cur_energy>max_energy)	//The path with higher energy
        {
            max_energy=cur_energy;
            max_jumps=step-1;
        }
        else if(cur_energy==max_energy && step-1>max_jumps) //The path with more steps
        {
            max_jumps=step-1;
        }
        return;
    }
    
    //recursive call
    for(int i=1;i<=n;i++)
    {
        if(valid(cur,i))
        {
            route[step]=i;		//���O���o�B 
            havejumped[i]=1;	//��o�B�аO��1 
            jump(i,step+1);
            havejumped[i]=0;	//�����O�o����L���a��]��0 
        }
    }
    
}
int main(void)
{
    scanf("%d%d%d",&n,&s,&t);
    
    for(int i=1;i<=n;i++)
    	scanf("%d",&height[i]);
    for(int i=1;i<=n;i++)
    	scanf("%d",&color[i]);
    	
    havejumped[s]=1;	//����o�B�аO���w���L 
    route[0]=s;		//�o�B�O�Ĥ@�B 
    jump(s,1);
    
    printf("%d %d\n",max_energy, max_jumps);
    
    return 0;
}
