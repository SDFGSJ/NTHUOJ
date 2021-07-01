#include<stdio.h>
#include<string.h>
int Q,R;
int plus[20];
int minus[20];
int used[10];
int ans;
int len;
void dfs(int a,int b){
	int i,j;
    if(a==R && b==Q){
        ans++;
        return;
    }
    if(a>R || b>Q)	return;
    
	for(i=0;i<len;i++){
        if(used[i]==-1){
            for(j=0;j<b;j++){
                if(a+b+i==plus[j] || a+b-i==minus[j] ){
                	break;
                }
            }                
            if(j!=b)	//如果沒有迴圈沒有跑完
            	continue;
            used[i]=a+b;
            dfs(a+1,b);	//放rook
            used[i]=-1;	//放完後要重設狀態
            if(b<Q){
                for(j=0;j<len;j++){
                    if(used[j]==-1)
                    	continue;
                    else{
                        if(used[j]-j==a+b-i || used[j]+j==a+b+i)
                        	break;
                    }
                }
                if(j==len){
                    plus[b]=a+b+i;
                    minus[b]=a+b-i;
                    used[i]=a+b;
                    dfs(a,b+1);	//放queen 
                    used[i]=-1;	//放完後要重設狀態 
                }
            }
        }
    }
}
int main(void){
    while(scanf("%d%d",&Q,&R)==2){
	    ans=0;
	    len=Q+R;
	    memset(used,-1,sizeof(used));
	    dfs(0,0);
	    printf("%d\n",ans);
    }
}
