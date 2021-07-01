#include<stdio.h>
char system[25],protect[25],ans[25][25];
int haveAns=0;
void run(char *s,char *p,int ansrow);
int main(void)
{
	scanf("%s%s",system,protect);
	run(system,protect,0);
	if(!haveAns){
		printf("What the hack!?\n");
	}
	return 0;
}
void run(char *s,char *p,int ansrow)
{
	int i;
	if(*s=='\0' || *p=='\0'){
		if(*s==*p){
			for(i=0;i<ansrow;i++){
				printf("%s",ans[i]);
				if(i==ansrow-1){
					printf("\n");
				}else{
					printf(" ");
				}
			}
			haveAns=1;
		}
		return;
	}
	if(*p=='#'){
		for(i=0;*(s+i)!='\0';i++){
			ans[ansrow][i]=*(s+i);
			ans[ansrow][i+1]='\0';
			run(s+i+1,p+1,ansrow+1); 
		}
	}
	if(*s==*p){
		run(s+1,p+1,ansrow);
	}
}
