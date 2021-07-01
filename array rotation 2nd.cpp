#include<stdio.h>
int main(void)
{
	int i,j,n,a[20][20],t_i=0,t_j=0;
	scanf("%d",&n);
	for(i=0;i<n;i++)
		for(j=0;j<n;j++)
			scanf("%d",&a[i][j]);
	i=0;
	while(i<n){
		t_i=i;j=0;t_j=j;
		while(t_i>=j&&t_j<=i){
			if(t_j!=i)
				printf("%d ",a[t_i][t_j]);
			else
				printf("%d\n",a[t_i][t_j]);
			t_i--;t_j++;
		}
		i++;
	}
	//printf("i=%d,j=%d,t_i=%d,t_j=%d",i,j,t_i,t_j);
	i=n-1;j=1;
	while(j<n){
		t_i=i;t_j=j;
		while(t_i>=0&&t_j<=i){
			if(t_j!=i)
				printf("%d ",a[t_i][t_j]);
			else
				printf("%d\n",a[t_i][t_j]);
			t_i--;t_j++;
		}
		j++;
	}
	return 0;
}
