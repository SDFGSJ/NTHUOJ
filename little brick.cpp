#include<stdio.h>
int gcd(int a,int b);
int lcm(int a,int b);
int power(int a,int b);
int main(void)
{
	int a,b,c,d;
	scanf("%d%d%d%d",&a,&b,&c,&d);
	printf("%d\n",gcd  ( lcm  ( power(a,b),c ),d ) );
	printf("%d\n",gcd  ( power( lcm  (a,b),c ),d ) );
	printf("%d\n",lcm  ( gcd  ( power(a,b),c ),d ) );
	printf("%d\n",lcm  ( power( gcd  (a,b),c ),d ) );
	printf("%d\n",power( gcd  ( lcm  (a,b),c ),d ) );
	printf("%d\n",power( lcm  ( gcd  (a,b),c ),d ) );
	return 0;
}
int gcd(int a,int b)
{
	if(a==0){
		return b;
	}else if(b==0){
		return a;
	}else{
		return gcd(b,a%b);
	}
}
int lcm(int a,int b)
{
	int ans;
	int common=gcd(a,b);
	a/=common;
	b/=common;
	ans=common*a*b;
	return ans;
}
int power(int a,int b)
{
	int ans;
	if(b==1){
		ans=a;
	}else if(b==0 || a==1){
		ans=1;
	}else{
		ans=a*power(a,b-1);
	}	
	return ans;
}
