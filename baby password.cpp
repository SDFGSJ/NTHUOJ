#include<stdio.h>
int main(void)
{
	char after;
	int shift;
	scanf("%c%d",&after,&shift);
	if(after-shift<'A')
		printf("%c\n",after-shift+26);
	else if(after-shift>'Z')
		printf("%c\n",after-shift-26);
	else
		printf("%c\n",after-shift);
	return 0;
}
