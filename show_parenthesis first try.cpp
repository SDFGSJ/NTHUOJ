#include<stdio.h>
int show_parenthesis(int n);
int main(void)
{
	int n;
	scanf("%d",&n);
	printf("=%d",show_parenthesis(n));
	return 0;
}
int show_parenthesis(int n)
{
	int prev_ans;
	if(n>1){
		if(n%2==0){
			prev_ans=show_parenthesis(n-1);
			printf("+%d",n);
			return prev_ans+n;			
		}else{
			printf("(");
			prev_ans=show_parenthesis(n-1);
			printf(")*%d",n);
			return prev_ans*n;
		}
	}else{
		printf("%d",n);
		return 1;
	}
}
