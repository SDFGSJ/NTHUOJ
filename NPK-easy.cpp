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
			if(find(line.begin(),line.end(),num) == line.end()){	//�o�Ӱ�a�S���X�{�L
				line.push_back(num);
			}
		}else{
			int num=line.front();	//���X����̫e������a
			cout<<country[num].front()<<"\n";
			country[num].pop();
			if(country[num].empty()){	//�o�Ӱ�a�w�g�S���H
				line.pop_front();	//�N�Ӱ�a���X����
			}
		}
	}
	return 0;
}