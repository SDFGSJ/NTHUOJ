#include<stdio.h>
#include<string.h>
int t,ans;
int len_sys,len_pro;
char system[30],protect[30];

void f(int index_a,int index_b,int c){
    if(index_a==len_sys && index_b==len_pro)	//�p�G����r�ꪺ�����ɡAans�N+1 
		ans++;
    else if(protect[index_b]=='#' && index_a<len_sys){	//�p�G�J�쪺�O'#'�ӥBsystem�r���٨S�쵲�� 
        f(index_a+1,index_b,0);		//system�]�U�@�Ӧr�Aprotect�d�b��a 
        f(index_a+1,index_b+1,0);	//system�]�U�@�Ӧr�Aprotect�]�U�@�Ӧr
    }
    else if(protect[index_b]=='$' && index_a<len_sys && (!c || c==system[index_a])){	//�p�G�J�쪺�O'$'�ӥBsystem�r���٨S�쵲�� 
        f(index_a+1,index_b,system[index_a]);	//system�]�U�@�Ӧr�Aprotect�d�b��a
        f(index_a+1,index_b+1,0);	//system�]�U�@�Ӧr�Aprotect�]�U�@�Ӧr
    }
    else if(index_a<len_sys && index_b<len_pro && system[index_a]==protect[index_b])	//�p�G��Ӧr�곣�٨S�쵲���ӥB�������r���ۦP 
		f(index_a+1,index_b+1,0);	//��ӳ��]�U�@�Ӧr 
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
