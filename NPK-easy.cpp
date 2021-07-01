#include<bits/stdc++.h>
using namespace std;
queue<int> country[3];
list<int> line;
int main(){
	string cmd;
	int n,id;

	cin>>n;
	while(n--){
		cin>>cmd;
		if(cmd=="ENQUEUE"){
			cin>>id;
			int num=id%3;
			country[num].push(id);
			if(find(line.begin(),line.end(),num) == line.end()){	//這個國家沒有出現過
				line.push_back(num);
			}
		}else{
			int num=line.front();	//取出隊伍最前面的國家
			cout<<country[num].front()<<"\n";
			country[num].pop();
			if(country[num].empty()){	//這個國家已經沒有人
				line.pop_front();	//將該國家移出隊伍
			}
		}
	}
	return 0;
}