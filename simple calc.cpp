#include<stdio.h>
int main(void)
{
	double a,b;
	char op;
	scanf("%lf%c%lf",&a,&op,&b);
	if(op=='+')
		printf("%.3f\n",a+b);
	else if(op=='-')
		printf("%.3f\n",a-b);
	else if(op=='*')
		printf("%.3f\n",a*b);
	else if(op=='/'){
		if(b==0)
			printf("Error\n");
		else
			printf("%.3f\n",a/b);
	}
	return 0;
}
