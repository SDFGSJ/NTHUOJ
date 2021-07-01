#include<bits/stdc++.h>
using namespace std;
set<pair<int,int>> wp;	//(weight,price)
set<pair<int,int>> pw;	//(price,weight)
map<pair<int,int>,int> m;

int main(){
	int n,q;
	cin>>n;
	while(n--){
		int weight,price;
		cin>>weight>>price;
		wp.insert({weight,price});
		pw.insert({price,weight});
	}
	cin>>q;
	while(q--){
		int type,weight,price;
		cin>>type;
		if(type==1){
			cin>>weight>>price;
			wp.insert({weight,price});
			pw.insert({price,weight});
		}else if(type==2){
			cin>>weight>>price;
			if( wp.count({weight,price})==1 ){	//this item exist
				cout<<"OK\n";
				wp.erase({weight,price});
				pw.erase({price,weight});
			}else{
				cout<<"No Item\n";
			}
		}else if(type==3){
			cin>>weight;
			auto wpit=wp.lower_bound({weight,-1});
			auto pwit=pw.lower_bound({wpit->second,wpit->first});
			if( wpit != wp.end() ){
				cout<<"OK"<<" "<<wpit->first<<" "<<wpit->second<<"\n";
				wp.erase(wpit);
				pw.erase(pwit);
			}else{
				cout<<"No Item\n";
			}
		}else{
			cin>>price;
			auto pwit=pw.upper_bound({price,-1});
			auto wpit=wp.upper_bound({pwit->second,pwit->first});
			printf("the pair i found at most %d is (%d,%d)\n",price,pwit->second,pwit->first);
			if(pwit==pw.begin()){
				if(pwit->first <= price){
					cout<<"OK"<<" "<<pwit->second<<" "<<pwit->first<<"\n";
					pw.erase(pwit);
					wp.erase(wpit);
				}else{
					cout<<"No Item\n";
				}
			}else{
				if(pwit->first > price){
					pwit--;
				}
				cout<<"OK"<<" "<<pwit->second<<" "<<pwit->first<<"\n";
				pw.erase(pwit);
				wp.erase(wpit);
			}
			/*if(pwit->first <= price){
				cout<<"OK"<<" "<<pwit->second<<" "<<pwit->first<<"\n";
				wp.erase(wpit);
				pw.erase(pwit);
			}else{
				cout<<"No Item\n";
			}*/
		}
		/**/printf("[wp]\n");
		for(auto i:wp){
			cout<<"("<<i.first<<","<<i.second<<")\n";
		}
		printf("[pw]\n");
		for(auto i:pw){
			cout<<"("<<i.first<<","<<i.second<<")\n";
		}
	}
	return 0;
}
