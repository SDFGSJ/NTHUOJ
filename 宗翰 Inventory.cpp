#include<stdio.h>

typedef struct{
    char s[25];
    int x,y;
}pokemon;

int n;

pokemon cmp[105];

int main(){
    scanf("%d",&n);
    for(int i=0;i<n;i++)
        scanf("%s%d%d",cmp[i].s,&cmp[i].x,&cmp[i].y);
    for(int i=0;i<n;i++){
        for(int j=0;j<i;j++){
            if(cmp[j].x == cmp[j].y && (cmp[i].x != cmp[i].y || cmp[j].x > cmp[i].x || (cmp[j].x == cmp[i].x && cmp[j].y>cmp[i].y) ) ){
                pokemon temp=cmp[i];
                cmp[i]=cmp[j];
                cmp[j]=temp;
            }
            else if (cmp[j].x != cmp[j].y && cmp[i].x != cmp[i].y && (cmp[j].x > cmp[i].x || (cmp[j].x == cmp[i].x && cmp[j].y>cmp[i].y) ) ){
                pokemon temp=cmp[i];
                cmp[i]=cmp[j];
                cmp[j]=temp;
            }
        }
    }
    for(int i=0;i<n;i++)
        printf("%s %d %d\n",cmp[i].s,cmp[i].x,cmp[i].y);
}
