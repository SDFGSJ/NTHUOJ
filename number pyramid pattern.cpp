#include<stdio.h>
int main(void)
{
	int n,p;
	int i,j;
	scanf("%d%d",&n,&p);
	
	if(p==1){
		for(i=n;i>0;i--){
			for(j=i;j>0;j--){
				printf("%d",i);
			}
			printf("\n");
		}
	}else if(p==2){
		for(i=n;i>0;i--){
			for(j=i;j>0;j--){
				printf("%d",j);
			}
			printf("\n");
		}
	}else{
		printf("Unrecognized pattern!\n");
	}
	return 0;
}
