#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "function.h"

#define STRING_SIZE 10000
char input_str[STRING_SIZE];
int changeCharacter(char *str, char a, char b);
int main()
{
    char a, b;
    scanf("%s", input_str);

    int T;
    scanf("%d", &T);
    while (T--)
    {
        scanf("%c", &a);	//¥Î¨Ó§l¦¬'\n'
        scanf("%c %c", &a, &b);
        changeCharacter(input_str, a, b);
    }
    printf("%s\n", input_str);
}
int changeCharacter(char *str, char a, char b)
{
	int i;
	int len=strlen(str);
	for(i=0;i<len;i++){
		if(str[i]==a){
			str[i]=b;
		}
	}
	return 1;
}
