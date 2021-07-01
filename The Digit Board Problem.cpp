#include<iostream>
#include<sstream>
#include<string>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<queue>
using namespace std;

queue<int>* myqueue;
int height[15];

int main(){
	stringstream ss;
	string input;
	int t,i;
	scanf("%d",&t);
	while(t--){
		int slot,round;
		scanf("%d%d",&slot,&round);
		myqueue=new queue<int> [slot+3] ;
		getline(cin,input);
		while(round--){
			int inslot=-1,num=-1;
			
			getline(cin,input);
			ss<<input;
			ss>>inslot;
			
			while(1){
				ss>>num;
				if(ss.fail()){
					break;
				}
				myqueue[inslot].push(num);
				height[inslot]++;
			}
			ss.clear();
		}
		
		/*for(i=0;i<slot;i++){
			printf("[%d]:size=%d\n",i,myqueue[i].size());
		}*/

		int max=-1;
		for(i=0;i<slot;i++){
			if(height[i]>max){
				max=height[i];
			}
		}
		//printf("max=%d\n",max);

		long long sum=0;
		while(max--){
			long long n=0;
			for(i=slot-1;i>=0;i--){
				if(myqueue[i].size()>0){
					n+=myqueue[i].front()*pow(10,(slot-i-1));
					myqueue[i].pop();
				}
			}
			//printf("n=%d\n",n);
			sum+=n;
		}
		printf("%lld\n",sum);
		
		memset(height,0,sizeof(height));
		delete [] myqueue;
	}
}
