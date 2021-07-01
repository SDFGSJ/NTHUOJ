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
    if(pos==t){		//�p�G�w�g������I 
        if(sum>=max_energy){
            max_energy=sum;
            max_jump=max(max_jump,jumps);
        }
        return;
    }
    visited[pos]=1;		//�O�o��{�b����m�аO��1
    for (i=1;i<=n;i++){
        if (visited[i]==0 && (abs(i-pos)==1 || color[i]==color[pos])){
            find(i, sum+abs(i-pos)*abs(height[i]-height[pos]) ,jumps+1);	//�b�o�䶶�K��energy 
        }
    }
    visited[pos]=0;		//���}�j���O�o����L����m�令0 
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
