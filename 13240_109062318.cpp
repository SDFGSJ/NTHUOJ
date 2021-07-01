#include<bits/stdc++.h>
using namespace std;
queue<int> country[3];
queue<int> vip;
list<int> line;
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	string cmd;
	int n,id;

	while(cin>>cmd){
		if(cmd=="ENQUEUE"){
			cin>>id;
			int num=id%3;
			if(id%5==0){	//vip
				vip.push(id);
			}else{
				country[num].push(id);
				if(find(line.begin(),line.end(),num) == line.end()){	//這個國家沒有出現過
					line.push_back(num);
				}
			}
			
		}else{
			int num;
			if(line.size()!=0){
				num=line.front();	//取出隊伍最前面的國家
			}
			
			if(vip.size()!=0){	//someone in vip
				cout<<vip.front();
				vip.pop();
				
				//printf("line size=%d\n",line.size());
				if(line.size()!=0){
					cout<<" "<<country[num].front()<<"\n";
					country[num].pop();
					if(country[num].empty()){	//這個國家已經沒有人
						line.pop_front();	//將該國家移出隊伍
					}
				}else{
					cout<<"\n";
				}
				//printf("a\n");
			}else{	//no one in vip
				cout<<country[num].front()<<"\n";
				country[num].pop();
				if(country[num].empty()){	//這個國家已經沒有人
					line.pop_front();	//將該國家移出隊伍
				}
			}
			
			/*if(country[num].empty()){	//這個國家已經沒有人
				line.pop_front();	//將該國家移出隊伍
			}*/
		}
		
	}
	return 0;
}
