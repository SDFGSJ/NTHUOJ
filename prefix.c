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
		//�P�_�^�Ǫ�ans�Odouble�٬Oint
		if( ans-(double)(int)ans>0 ){	//�]�i�H�g��ans!=(int)ans 
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
    
    while( isspace(c=getchar()) )	//Ū���ť� 
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
		ungetc(c,stdin);	//�NŪ�쪺�Ʀr�R�^�h 
		scanf("%lf",&num);
		printf("%d ",(int)num);//p.s.�D�F���|��double���Ʀr				
	}
	return num;
}
