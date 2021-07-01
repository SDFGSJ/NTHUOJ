#include<stdio.h>
struct K{
    char name[25];
    int hp, max_hp;
}p[100];
int n;
int main(void){
	int i,j;
    scanf("%d",&n);
    for(i=0;i<n;i++){
    	scanf("%s%d%d",p[i].name,&p[i].hp,&p[i].max_hp);
	}
	for(i=0;i<n;i++){
		for(j=0;j<i;j++){
			if(p[i].hp!=p[i].max_hp && (p[j].hp==p[j].max_hp || p[j].hp>p[i].hp || p[j].hp==p[i].hp && p[j].max_hp>p[i].max_hp) || p[j].hp==p[j].max_hp && p[j].hp>p[i].hp){ 
                K c = p[i];
                p[i] = p[j], 
				p[j] = c;
            }
		}
	}
    for(i=0;i<n;i++){
    	printf("%s %d %d\n",p[i].name,p[i].hp,p[i].max_hp);
	}
    return 0;
}
