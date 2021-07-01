#include<stdio.h>
#include<math.h>
#include<limits.h>

int N;
int height[50];
int route[50];
int color[50];
int max_energy=INT_MIN;
int max_steps=INT_MIN;

int cost(int steps){
    int totenergy = 0;
    for(int i=0;i<steps;i++){
        totenergy += abs(height[ route[i] ]-height[ route[i+1] ])*abs(route[i]-route[i+1]);
    }
    return totenergy;
}

void jump(int pos,int end,int steps){
    if(pos==end){	//如果已經走到了盡頭 
        int cur_energy=cost(steps-1);
        if(cur_energy>max_energy){
            max_energy=cur_energy;
            max_steps=steps-1;
        }
        else if(cur_energy==max_energy && steps-1>max_steps){
            max_steps=steps-1;
        }
        return;
    }
        
    for(int i=1;i<=N;i++){
        int flag=0;		//flag用來檢查這個石頭有沒有在前面出現過 
        for(int j=0;j<steps;j++){
            if(route[j]==i) flag=1;		//如果該石頭在前面出現過，就把flag標記為1 
        }
        if(!flag){	//如果這個石頭之前沒有走過 
            if(abs(pos-i)==1 || color[i]==color[pos]){
                route[steps]=i;		//記錄現在走的石頭 
                jump(i,end,steps+1);
            }
        }
    }
}

int main(void){
    int S,T;
    scanf("%d%d%d",&N,&S,&T);
    
    for(int i=1;i<=N;i++) scanf("%d",&height[i]);
    for(int i=1;i<=N;i++) scanf("%d",&color[i]);
    
    route[0]=S;		//記錄第一步 
    jump(S,T,1);
    printf("%d %d\n",max_energy,max_steps);
    return 0;
}
