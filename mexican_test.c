#include<stdio.h>
int main(void){
    int T,a,m,n,t;
    scanf("%d", &T);
    //a = T;
    while (T > 0){
        scanf("%d%d%d", &n,&m,&t);
        for(int i = 0 ; i < n ; i++){
            if(i >= t-m && i < t){
                printf("^");
            }else{
                printf("-");
            }
        }
        T--;
        printf("\n");
    }
}
