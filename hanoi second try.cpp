#include<stdio.h>
void hanoi(char from,char to,char buffer,int n);
int main(void)
{
	int n;
	scanf("%d",&n);
	hanoi('1','3','2',n);
	return 0;
}
void hanoi(char a,char b,char c,int n)
{
	if(n==1){
		printf("%d\n",n);
		return;
	}
	hanoi(a,c,b,n-1);
	printf("%d\n",n);
	hanoi(c,b,a,n-1);
}
