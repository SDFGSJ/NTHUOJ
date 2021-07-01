//其實只要算2*(max-min)就好
#include<stdio.h>
#include<limits.h>
int place[200010];
int main(void)
{
	int i;
	int n,min=INT_MAX,max=INT_MIN;
	scanf("%d",&n);
	for(i=0;i<n+1;i++)
	{
		scanf("%d",&place[i]);
		if(place[i]>max){
			max=place[i];
		}
		if(place[i]<min){
			min=place[i];
		}
	}
	printf("%d\n",2*(max-min));
	return 0;
}
