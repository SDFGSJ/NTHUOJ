#include<stdio.h> 
#include<ctype.h>
double prefix();
int main(void)
{
	int test;
	double ans;
	
	scanf("%d",&test);
	while(test--)
	{	
		ans=prefix();
		//判斷回傳的ans是double還是int
		if( ans-(double)(int)ans>0 ){	//也可以寫成ans!=(int)ans 
			printf("= %.1f\n",ans);			
		}else{
			printf("= %d\n",(int)ans);
		}		
	}
	return 0;
}

double prefix()
{
	double num;
	double op1,op2;
    char c;
    
    while( isspace(c=getchar()) )	//讀掉空白 
		continue;
    
	if(c=='+'){
		printf("( ");
		
		op1=prefix();
		
		printf("+ ");
		
		op2=prefix();		
		
		printf(") ");
		
		num=op1+op2;
	}else if(c=='-'){
		printf("( ");
		
		op1=prefix();		
		
		printf("- ");
		
		op2=prefix();

		printf(") ");
		
		num=op1-op2;
	}else if(c=='*'){
		printf("( ");
		
		op1=prefix();		
		
		printf("* ");
		
		op2=prefix();

		printf(") ");
		
		num=op1*op2;
	}else if(c=='/'){
		printf("( ");
		
		op1=prefix();	
		
		printf("/ ");
		
		op2=prefix();

		printf(") ");
		
		num=op1/op2;
	}else if(isdigit(c)){
		ungetc(c,stdin);	//將讀到的數字吐回去 
		scanf("%lf",&num);
		printf("%d ",(int)num);//p.s.題幹不會有double的數字				
	}
	return num;
}
