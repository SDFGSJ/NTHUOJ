#include<stdio.h>
#define MAXN 100005
#define MAXS 1000005
int arr[MAXN],coef[MAXN];
char s[MAXS];
int pos;
int p,q;

int getNumber(){
    int ret=0;
    while('0'<=s[pos] && s[pos]<='9'){
    	ret=ret*10+s[pos]-'0';
		pos++;
	}
    return ret;
}

int build(int nowCoef){
    int ret;
    //printf("pos=%d,nowcoef=%d\n",pos,nowCoef);
    if(s[pos]!='f'){
        int idx=getNumber();
        //printf("idx=%d\n",idx);
        
        coef[idx]=((long long)coef[idx] + nowCoef) % q;
        //printf("coef[%d]=%d\n",idx,coef[idx]);
        
        //printf("nowcoef=%d,arr[%d]=%d\n",nowCoef,idx,arr[idx]);
        ret=((long long)nowCoef * arr[idx]) % q;
    }else{
        pos+=2;
        
        int lVal=build( ((long long)nowCoef * p) % q );
        //printf("lval=%d\n",lVal);
        
        pos++;
        
        int rVal=build(nowCoef);
        //printf("rval=%d\n",rVal);
        
        pos++;
        
        ret=((long long)lVal + rVal) % q;
    }
    //printf("ret=%d\n",ret);
    return ret;
}
int main(){
	int i;   
    scanf("%d%d",&p,&q);
    
    int n;
    scanf("%d",&n);
    for(i=1;i<=n;i++)
        scanf("%d",&arr[i]);
    
	scanf("%s",s);
    int ans=build(1);
    
    /*printf("coef[]=");
    for(i=1;i<=n;i++){
    	printf("%d,",coef[i]);
	}
    printf("\n");*/
    
    int m;
	scanf("%d",&m);
    while(m--){
        int d,v;
        scanf("%d%d",&d,&v);

		ans = ((ans + (long long)coef[d] * (-arr[d] + v)) % q + q) % q;	//+q是為了處理負數的情況
        printf("%d\n",ans);
        
		arr[d]=v;
    }
    return 0;
}
