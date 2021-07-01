#include<bits/stdc++.h>
using namespace std;

vector<int> readvector();
int getvalue(vector<int>);
void printvector(vector<int>);
struct mycmp{
	bool operator()(const vector<int>& lhs,const vector<int>& rhs){
		return getvalue(lhs)<getvalue(rhs);
	}
};

int main(){
	int i,j;
	set<vector<int>,mycmp> s;
	set<vector<int>,mycmp>::iterator it;
	
	string cmd;
	while(cin>>cmd){
		if(cmd=="insert"){
			vector<int> t=readvector();
			int tsum=getvalue(t);
			
			for(it=s.begin();it!=s.end();it++){	//檢查set中有沒有key一樣的vector
				if(getvalue(*it)==tsum){
					s.erase(*it);
					int size=t.size();
					for(i=0;i<size;i++){	//reverse vector
						int tmp=t[i];
						t[i]=t[size-1-i];
						t[size-1-i]=tmp;
					}
					break;
				}
			}
			
			s.insert(t);
		}else if(cmd=="range_out"){
			int from=getvalue(readvector());
			int to=getvalue(readvector());
			
			for(it=s.begin();it!=s.end();it++){
				int key=getvalue(*it);
				if(from<=key && key<=to){
					printvector(*it);
				}else if(key>to){	//優化
					break;
				}
			}
		}else{
			for(it=s.begin();it!=s.end();it++){
				printvector(*it);
			}
		}
	}
	return 0;
}
vector<int> readvector(){
	int num;
	vector<int> newvec;
	
	while(cin>>num){
		if(num==0){
			break;
		}
		newvec.push_back(num);
	}
	return newvec;
}
int getvalue(vector<int> v){
	int i,sum=0;
	for(i=0;i<v.size();i++){
		sum+=v[i]*(v.size()-i);
	}
	return sum;
}
void printvector(vector<int> v){
	int i;
	for(i=0;i<v.size();i++){
		cout<<v[i]<<" ";
	}
	cout<<"\n";
}
