#include<stdio.h>
char system[20],protect[20],ans[20][21];
int haveAns;

void run(char *s,char *p,int row);
int main(void)
{
	scanf("%s%s",system,protect);
	run(system,protect,0);
	
	if(!haveAns){
		printf("What the hack!?\n");
	}
	return 0;
}
void run(char *s,char*p,int row)
{
	int i;
	if(*s=='\0' || *p=='\0'){
		if(*s==*p){
			for(i=0;i<row;i++){
				printf("%s",ans[i]);
				if(i==row-1){
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
			ans[row][i]=*(s+i);
			ans[row][i+1]='\0';
			run(s+i+1,p+1,row+1);
		}
	}else if(*s==*p){
		run(s+1,p+1,row);
	}
	return;
}
