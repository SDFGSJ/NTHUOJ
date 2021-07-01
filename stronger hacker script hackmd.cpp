#include<stdio.h>
#include<string.h>
int t,ans;
int len_sys,len_pro;
char system[30],protect[30];

void f(int index_a,int index_b,int c){
    if(index_a==len_sys && index_b==len_pro)	//如果都到字串的結尾時，ans就+1 
		ans++;
    else if(protect[index_b]=='#' && index_a<len_sys){	//如果遇到的是'#'而且system字串還沒到結尾 
        f(index_a+1,index_b,0);		//system跑下一個字，protect留在原地 
        f(index_a+1,index_b+1,0);	//system跑下一個字，protect跑下一個字
    }
    else if(protect[index_b]=='$' && index_a<len_sys && (!c || c==system[index_a])){	//如果遇到的是'$'而且system字串還沒到結尾 
        f(index_a+1,index_b,system[index_a]);	//system跑下一個字，protect留在原地
        f(index_a+1,index_b+1,0);	//system跑下一個字，protect跑下一個字
    }
    else if(index_a<len_sys && index_b<len_pro && system[index_a]==protect[index_b])	//如果兩個字串都還沒到結尾而且對應的字都相同 
		f(index_a+1,index_b+1,0);	//兩個都跑下一個字 
}
int main(void)
{
    scanf("%d",&t);
    while(t--)
	{
        scanf("%s%s",system,protect);
        len_sys = strlen(system);
		len_pro = strlen(protect);
		ans = 0;
        f(0,0,0);
        printf("%d\n",ans);
    }
    return 0;
}
