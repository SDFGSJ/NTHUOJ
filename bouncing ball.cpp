#include<stdio.h>
#include<math.h>
long long end[3],place[3],v[3],displace[3];
int main(void)
{
	long long time;
	int t,i,j;
	scanf("%d",&t);
	while(t--)
	{
		for(i=0;i<3;i++)
			scanf("%lld",&end[i]);
		for(i=0;i<3;i++)
			scanf("%lld",&place[i]);
		for(i=0;i<3;i++)
			scanf("%lld",&v[i]);
		scanf("%lld",&time);
		for(i=0;i<3;i++){
			place[i]+=(v[i]*time)%(2*end[i]);
			while(place[i]>end[i] || place[i]<0){
				if(place[i]>end[i]){
					place[i]=end[i]-(place[i]-end[i]);
				}else{
					place[i]=-place[i];
				}
			}
		}
		printf("%lld %lld %lld\n",place[0],place[1],place[2]);
	}
	return 0;
}
