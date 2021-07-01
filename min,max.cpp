#include<stdio.h>
#include<stdlib.h>
int main(void)
{
	int n,m,min=0,max=0,min_i,min_j,max_i,max_j;	
	int a[10][10]={0};
	int i,j;
	
	scanf("%d%d",&n,&m);
	
	for(i=0;i<n;i++)
		for(j=0;j<m;j++)
			scanf("%d",&a[i][j]);
		
	
	
	min=a[0][0],max=a[0][0];
	
	for(i=0;i<n;i++){
		for(j=0;j<m;j++){
			if(a[i][j]<=min){
				min=a[i][j];
				min_i=i;
				min_j=j;
			}else if(a[i][j]>=max){
				max=a[i][j];
				max_i=i;
				max_j=j;
			}
		}
	}
	printf("%d %d",abs(max_i-min_i)+abs(max_j-min_j),max-min);
	return 0;
}
