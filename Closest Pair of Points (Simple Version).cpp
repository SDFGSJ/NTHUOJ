#include<bits/stdc++.h>
using namespace std;
int x[100010];
int y[100010];
int main(){
	int t,i;
	scanf("%d",&t);
	while(t--){
		int n;
		int tmpx,tmpy,xidx=0,yidx=0;
		scanf("%d",&n);
		for(i=0;i<2*n;i++){
			scanf("%d%d",&tmpx,&tmpy);
			if(tmpx!=0){
				if(tmpx>0){
					x[xidx++]=tmpx;
				}else{
					x[xidx++]=-tmpx;
				}
			}else{
				if(tmpy>0){
					y[yidx++]=tmpy;
				}else{
					y[yidx++]=-tmpy;
				}
			}
		}
		sort(x,x+n);
		sort(y,y+n);
		/*printf("xidx=%d,yidx=%d\n",xidx,yidx);
		for(i=0;i<xidx;i++){
			printf("%d,",x[i]);
		}
		printf("\n");
		for(i=0;i<yidx;i++){
			printf("%d,",y[i]);
		}
		printf("\n");*/
		double ans=0.0;
		for(i=0;i<n;i++){
			ans+=sqrt(1.0*x[i]*x[i] + 1.0*y[i]*y[i]);
		}
		printf("%.8lf\n",ans);
	}
	return 0;
}
