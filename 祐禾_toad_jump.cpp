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
    if(pos==end){	//�p�G�w�g����F���Y 
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
        int flag=0;		//flag�Ψ��ˬd�o�ӥ��Y���S���b�e���X�{�L 
        for(int j=0;j<steps;j++){
            if(route[j]==i) flag=1;		//�p�G�ӥ��Y�b�e���X�{�L�A�N��flag�аO��1 
        }
        if(!flag){	//�p�G�o�ӥ��Y���e�S�����L 
            if(abs(pos-i)==1 || color[i]==color[pos]){
                route[steps]=i;		//�O���{�b�������Y 
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
    
    route[0]=S;		//�O���Ĥ@�B 
    jump(S,T,1);
    printf("%d %d\n",max_energy,max_steps);
    return 0;
}
