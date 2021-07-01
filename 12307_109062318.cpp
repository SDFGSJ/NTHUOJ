#include<bits/stdc++.h>
using namespace std;

map<string,string> mstr;
map<string,int> mcnt;
set<string> s;
char tmp[5000010];
char origin[5000010];
char str[5000010];	//after tolower and sort

int main(){
	int n,i;
	cin>>n;
	while(n--){
		scanf("%s",tmp);
		int len=strlen(tmp);
		
		for(i=0;i<=len;i++){
			str[i]=tolower(tmp[i]);
			origin[i]=tmp[i];
		}
		
		sort(str,str+len);
		
		//printf("str=%s,origin=%s\n",str,origin);
		string s=str,o=origin;
		mstr[s]=o;
		mcnt[s]++;
	}
	/*printf("mstr=\n");
	for(auto i: mstr){
		cout<<i.first<<":"<<i.second<<"\n";
	}
	printf("mcnt=\n");
	for(auto i: mcnt){
		cout<<i.first<<":"<<i.second<<"\n";
	}*/
	for(auto i:mcnt){
		if(i.second==1){
			s.insert(mstr[i.first]);
		}
	}
	for(auto i:s){
		cout<<i<<"\n";
	}
	return 0;
}
