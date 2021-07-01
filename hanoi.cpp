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
		printf("%d\n",n);
		return;
	}
	
	hanoi(n-1,a,c,b);
	
	printf("%d\n",n);
	
	hanoi(n-1,c,b,a);
}
