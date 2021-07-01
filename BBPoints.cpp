#include<bits/stdc++.h>
using namespace std;
//兩個set是為了方便lowerbound、加速
set<pair<long long,long long>> sxy;	//(x,y)
set<pair<long long,long long>> syx;	//(y,x)
int main(){
	int i,j;
	int n,q;
	set<pair<long long,long long>>::iterator xy_it,yx_it;
	
	scanf("%d%d",&n,&q);
	
	for(i=1;i<=n;i++){
		sxy.insert({i,0});
		syx.insert({0,i});
	}
	
	while(q--){
		int type;
		scanf("%d",&type);
		
		if(type==1){
			long long p,u;
			scanf("%lld%lld",&p,&u);
			
			xy_it=sxy.lower_bound({p,-2e9});
			yx_it=syx.lower_bound({xy_it->second,xy_it->first});	//利用xy_it的兩個值來找y,x
			
			/*printf("1:(x,y)=(%d,%d)\n",xy_it->first,xy_it->second);
			printf("1:(y,x)=(%d,%d)\n",yx_it->first,yx_it->second);*/
			
			long long newx=xy_it->first;
			long long newy=xy_it->second + u;
			
			sxy.erase(xy_it);
			sxy.insert({newx,newy});
			
			syx.erase(yx_it);
			syx.insert({newy,newx});
		}else{
			long long x,y,v;
			scanf("%lld%lld%lld",&x,&y,&v);
			
			yx_it=syx.lower_bound({y,x});
			xy_it=sxy.lower_bound({yx_it->second,yx_it->first});	//利用yx_it的兩個值來找x,y
			
			/*printf("2:(x,y)=(%d,%d)\n",xy_it->first,xy_it->second);
			printf("2:(y,x)=(%d,%d)\n",yx_it->first,yx_it->second);*/
			
			if(x <= yx_it->second && yx_it->second <= x+v && yx_it->first==y){	//注意y要一樣才需要更新
				long long newx,newy,dx;
				dx=yx_it->second-x;
				newx=yx_it->second;
				newy=yx_it->first-dx;
				
				sxy.erase(xy_it);
				sxy.insert({newx,newy});
				
				syx.erase(yx_it);
				syx.insert({newy,newx});
			}
		}
	}
	for(xy_it=sxy.begin();xy_it!=sxy.end();xy_it++){
		if(xy_it==sxy.begin()){
			printf("%lld",xy_it->second);
		}else{
			printf(" %lld",xy_it->second);
		}
	}
	printf("\n");
	
	/*for(auto i:sxy){
		printf("(%d,%d),",i.first,i.second);
	}
	printf("\n");
	for(auto i:syx){
		printf("(%d,%d),",i.second,i.first);
	}
	printf("\n");*/
	return 0;
}
