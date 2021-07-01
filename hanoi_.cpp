#include<stdio.h>
void hanoi(int n,char from,char to,char buffer);
int main(void)
{
	int n;
	scanf("%d",&n);
	hanoi(n,'A','C','B');
	return 0;
}
void hanoi(int n,char a,char b,char c)
{
	if(n==1){
		printf("move disk %d from rod %c to rod %c\n",n,a,b);
		return;
	}
	
	hanoi(n-1,a,c,b);
	
	printf("move disk %d from rod %c to rod %c\n",n,a,b);
	
	hanoi(n-1,c,b,a);
}
