#include<stdio.h>
#include<string.h>
char input[100005];
int main(void)
{
	while( scanf("%s",input)!=EOF )
	{
		int flag=0;
		for(int i=0;i<strlen(input);i++)
		{
			if(input[i]!=input[strlen(input)-1-i]){
				flag=1;
				break;
			}
		}
		if(!flag)
			printf("Yes\n");
		else
			printf("No\n");		
	}
	return 0;
}
