#include<stdio.h>
int main(void)
{
	int m,n,i,j,k,time,r1,r2,c1,c2,max=0;
	scanf("%d%d",&m,&n);
	int a[m][n];
	for(i=0;i<m;i++)
		for(j=0;j<n;j++)
			scanf("%d",&a[i][j]);
	scanf("%d",&time);
	for(k=0;k<time;k++)
	{
		max=0;
		scanf("%d%d%d%d",&r1,&r2,&c1,&c2);
		for(i=r1-1;i<r2;i++)
			for(j=c1-1;j<c2;j++)			
				if(a[i][j]>max)
					max=a[i][j];									
		printf("%d\n",max);
	}
	return 0;
}
