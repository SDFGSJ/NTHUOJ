#include<stdio.h>
void hanoi(char from,char to,char buffer,int n);
int main(void)
{
	int n;
	printf("number of disks:");
	scanf("%d",&n);
	hanoi('A','C','B',n);
	return 0;
}
void hanoi(char a,char b,char c,int n)
{
	if(n==1){
		printf("move the top disk from tower %c to tower %c\n",a,b);
		return;
	}
	
	hanoi(a,c,b,n-1);
	
	printf("move the top disk from tower %c to tower %c\n",a,b);
	
	hanoi(c,b,a,n-1);
	
}
