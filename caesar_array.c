#include<stdio.h>
int main(void)
{
    char input[3];
    int a,i;
    scanf("%s%d",input,&a);
    a=a%26;
    for(i=0;i<3;i++)
    {
        if(input[i]+a<'A')
        {
            printf("%c",input[i]+a+26);
        }
        else if(input[i]+a>'Z')
        {
            printf("%c",input[i]+a-26);
        }
        else
        {
            printf("%c",input[i]+a);
        }
    }
    printf("\n");
    return 0;
}