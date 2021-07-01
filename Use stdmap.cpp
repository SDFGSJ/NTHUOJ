#include<cassert>
#include<iostream>
#include<map>
#include<ostream>
#include<string>
#include<cstddef>
#include<bits/stdc++.h>
namespace oj
{
	struct String
	{
		std::string str;
		String(const std::string &);
		String(const String &);
		String& operator=(const String &);
	};

	std::ostream& operator<<(std::ostream &,const String &);

	void insert(std::map<int,String> &ma,int key,const std::string &str);
	void output(const std::map<int,String> &ma,int begin,int end);
	void erase(std::map<int,String> &ma,int begin,int end);

	std::ostream& operator<<(std::ostream &,const std::map<int,String> &);
}

namespace oj
{
	String::String(const std::string &str_)
		:str(str_){}

	String::String(const String &rhs)
		:str(rhs.str){}

	String& String::operator=(const String &rhs)
	{
		str=rhs.str;
		return *this;
	}

	std::ostream& operator<<(std::ostream &os,const String &str)
	{
		return os<<str.str;
	}
}
using namespace std;
using namespace oj;
int main()
{
	map<int,String> ma;
	for(string cmd;cin>>cmd;)
	{
		if(cmd=="insert")
		{
			int key;
			cin>>key>>cmd;
			insert(ma,key,cmd);
		}
		else
			if(cmd=="range")
			{
				int begin,end;
				cin>>cmd>>begin>>end;
				if(cmd=="output")
					output(ma,begin,end);
				else
					if(cmd=="erase")
						erase(ma,begin,end);
					else
						assert(false);
			}
			else
				assert(false);
		cout<<ma<<endl;
	}
}
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
