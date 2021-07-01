#include <bits/stdc++.h>
using namespace std;

multiset<pair<int,int>> wp;
multiset<pair<int,int>> pw;
int N,Q;
int main(){
    cin>>N;
    int tem1,tem2,tem3;
    while(N--){
        cin>>tem1>>tem2;
        wp.insert({tem1,tem2});
        pw.insert({tem2,tem1});
    }
    cin>>Q;
    while(Q--){
        cin>>tem1;
        if(tem1<=2){
            cin>>tem2>>tem3;
            if(tem1==1){
                wp.insert({tem2,tem3});
                pw.insert({tem3,tem2});
            }
            else if(tem1==2){
                if(wp.size()==0){
                    cout<<"No Item\n";
                }else{
	                auto i=wp.find({tem2,tem3});
	                if(i!=wp.end()){
	                    wp.erase(i);
	                    auto i=pw.find({tem3,tem2});
	                    pw.erase(i);
	                    cout<<"OK\n";
	                }else{
	                    cout<<"No Item\n";
	                }
                }
            }
        }else{
            cin>>tem2;
            if(wp.size()==0){
                cout<<"No Item\n";
            }else{
	            if(tem1==3){
	                auto i=wp.lower_bound({tem2,INT_MIN});
	                if(i!=wp.end() && i->first>=tem2){
	                    int t1=i->first;
	                    int t2=i->second;
	                    wp.erase(i);
	                    auto i=pw.find({t2,t1});
	                    pw.erase(i);
	                    cout<<"OK "<<t1<<" "<<t2;
	                    cout<<'\n';
	                }else{
	                    cout<<"No Item\n";
	                }
	            }else if(tem1==4){
	                auto i=pw.lower_bound({tem2,INT_MIN});
	                if( (pw.begin()->first)>tem2 ){
	                    cout<<"No Item\n";
	                }else{
		                if(i!=pw.end() && i->first==tem2){
		                    auto j=wp.find({i->second,i->first});
		                    cout<<"OK "<<j->first<<" "<<j->second<<'\n';
		                    wp.erase(j);
		                    pw.erase(i);
		                }else{
			                int t1,t2;
			                if( i!=pw.begin() && ( i==pw.end() || i->first!=tem2 ) ){
			                    --i;
			                    
			                    if(i!=pw.begin()){
			                        auto j=i;
			                        j--;
			                        while(j->first==i->first && j!=pw.begin()){
			                            i--;
			                            j--;
			                        }
			                        if(j->first==i->first)
			                        i=j;   
			                    }
			                    
			                    t1=i->first;
			                    t2=i->second;
			                    pw.erase(i);
			                    auto j=wp.find({t2,t1});
			                    wp.erase(j);
			                    cout<<"OK "<<t2<<" "<<t1<<'\n';
			                }
		                }
	                }
	            }
            }
        }
    }
}
