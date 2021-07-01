#include<stdio.h>
#include<math.h>

int n,s,t;
int color[25],height[25],visited[25];
int max_energy=-1,max_jump=-1;

int max(int x,int y) {
    return x>y ? x:y;
}

void find(int pos,int sum,int jumps){	//pos-->current position
    int i;
    if(pos==t){		//如果已經跳到終點 
        if(sum>=max_energy){
            max_energy=sum;
            max_jump=max(max_jump,jumps);
        }
        return;
    }
    visited[pos]=1;		//記得把現在的位置標記成1
    for (i=1;i<=n;i++){
        if (visited[i]==0 && (abs(i-pos)==1 || color[i]==color[pos])){
            find(i, sum+abs(i-pos)*abs(height[i]-height[pos]) ,jumps+1);	//在這邊順便算energy 
        }
    }
    visited[pos]=0;		//離開迴圈後記得把跳過的位置改成0 
}

int main(void){
    int i;
    
    scanf("%d%d%d",&n,&s,&t);
    for(i=1;i<=n;i++){
        scanf("%d",&height[i]);
    }
    for(i=1;i<=n;i++){
        scanf("%d",&color[i]);
    }
    
    find(s,0,0);
    
	printf("%d %d\n",max_energy,max_jump);
    return 0;
}
