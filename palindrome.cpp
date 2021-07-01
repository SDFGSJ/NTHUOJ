#include<stdio.h>
#include<string.h>
char word[100000];
int main(void)
{
	while( scanf("%s",word)!=EOF )
	{
		int len=strlen(word);
		int flag=0;
		for(int i=0;i<len;i++){
			if(word[i]!=word[ (len-1) - i ]){
				flag=1;
				break;
			}
		}
		if(flag)
			printf("No\n");
		else
			printf("Yes\n");
	}
	return 0;
}
