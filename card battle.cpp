#include<stdio.h>
int main(void)
{
	int a[3][3];
	int x,y,i,j,min=0,count=0;
	for(i=0;i<3;i++)	
		for(j=0;j<3;j++)
			scanf("%d",&a[i][j]);
	scanf("%d%d",&x,&y);
	min=a[x][y];
	
	for(i=0;i<3;i++){
		for(j=0;j<3;j++){
			if(a[i][j]<min)
				count++;
		}
	}
	printf("%.3f\n",count/8.0);
	/*for(i=0;i<3;i++){
		for(j=0;j<3;j++){
			printf("%4d",a[i][j]);
		}
		printf("\n");
	}*/	
	return 0;
}
