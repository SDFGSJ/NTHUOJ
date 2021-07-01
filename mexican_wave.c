#include<stdio.h>
int main(void)
{
    int x,people,max,t,i,j;
    scanf("%d",&x);       
    for(i=0;i<x;i++)
    {
        scanf("%d%d%d",&people,&max,&t);
        for(j=0;j<people;j++)
        {
            if(t-max<=j&&j<t)
                printf("^");
            else
                printf("-");               
        }
        printf("\n");
    }
    return 0;
}
