#include<stdio.h>
int gcd(int,int);
int main(void)
{
	int num1,num2;
	scanf("%d%d",&num1,&num2);
	printf("%d\n",gcd(num1,num2));
	return 0;
}
int gcd(int a,int b)
{
	if(a!=0&&b!=0){
		if(a>b){
			a%=b;
			return gcd(a,b);
		}else if(a<b){
			b%=a;
			return gcd(a,b);
		}else{
			return a;
		}
	}
	if(a==0)
		return b;
	if(b==0)
		return a;
}
