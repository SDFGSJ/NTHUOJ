#include"function.h" 
#include<bits/stdc++.h>
using namespace std;
void oj::insert(std::map<int,String>& ma,int key,const std::string& str){
	string tmp;
	auto test=ma.find(key);
	if(test!=ma.end()){
		tmp=str+test->second.str;
		ma.erase(test);
	}else{
		tmp=str;
	}
	ma.insert( pair<int,String>( key,String(tmp) ) );
}
void oj::output(const std::map<int,String>& ma,int begin,int end){
	for(auto i:ma){
		if(begin<=i.first && i.first<=end){
			cout<<i.second<<" ";
		}
	}
}
void oj::erase(std::map<int,String> &ma,int begin,int end){
	/*WA:iterator broken
	for(auto i:ma){
		cout<<"size="<<ma.size()<<"\n";
		cout<<"the key now="<<i.first<<"\n";
		if(begin<=i.first && i.first<=end){
			ma.erase(i.first);
		}
	}*/
	map<int,String>::iterator it;
	for(it=ma.begin();it!=ma.end();){
		if(begin<=it->first && it->first<=end){
			it=ma.erase(it);
		}else{
			it++;
		}
	}
	
	
	/*AC
	set<int> erasekey;
	for(auto i:ma){
		if(begin<=i.first && i.first<=end){
			erasekey.insert(i.first);
		}
	}
	
	for(auto i:erasekey){
		ma.erase(i);
	}*/
}
std::ostream& oj::operator<<(std::ostream& output,const std::map<int,String>& m){
	for(auto i:m){
		output<<i.second<<" ";
	}
	return output;
}
