#include<stdio.h>
char system[25],protect[25];
int count=0;
void run(char *s,char *p);
int main(void)
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%s%s",system,protect);
		run(system,protect);
		printf("%d\n",count);
		count=0;
	}
	return 0;
}
void run(char *s,char *p)
{
	int i;
	if(*s=='\0' || *p=='\0'){
		if(*s==*p)
			count++;
		return;
	}
	
	if(*p=='#'){
		for(i=0;*(s+i)!='\0';i++)
			run(s+i+1,p+1);
	}else if(*p=='$'){
		for(i=0;*(s+i)!='\0';i++){
			if(*(s+i)==*s)
				run(s+i+1,p+1);
			else
				return;
		}
	}else if(*s==*p){
		run(s+1,p+1);
	}
}
