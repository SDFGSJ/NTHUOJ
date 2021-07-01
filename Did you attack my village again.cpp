#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<string>
using namespace std;
struct Node{
	long long x;
	Node *next,*prev;
};
Node *first,*last,*d_head,*d_tail;
void house(long long);
void bomb(long long,long long);
void printfront();
void printend();
int main(){
	int t;
	scanf("%d",&t);
	
	//initialize dummy node
	d_head=(Node*)malloc(sizeof(Node));
	d_tail=(Node*)malloc(sizeof(Node));
	d_head->x = 1e11;
	d_head->next = d_tail;
	
	d_tail->x = 1e11;
	d_tail->prev = d_head;
	
	first=d_head;
	last=d_tail;
	
	while(t--){
		string command;
		cin>>command;
		if(command=="House"){
			long long a;
			scanf("%lld",&a);
			house(a);
		}else if(command=="Bomb"){
			long long a,b;
			scanf("%lld%lld",&a,&b);
			long long lower=a-b;
			long long upper=a+b;
			bomb(lower,upper);
		}else if(command=="PrintFront"){
			printfront();
		}else{
			printend();
		}
	}
	
	Node *tmp=first,*now=first;
	while(now!=last){
		now=now->next;
		free(tmp);
		tmp=now;
	}
	free(now);  //記得free掉最後一個node
	
	return 0;
}
void house(long long x){
	Node *newhouse=NULL,*it;
	
	//檢查一下x是否已經有房子
	int exist=0;
	for(it=first->next;it!=last;it=it->next){
		if(it->x==x){
			exist=1;
		}
	}
	if(exist) return;
	
	if(first->next==last){  //如果插入的是第一個node
		newhouse=(Node*)malloc(sizeof(Node));
		newhouse->x=x;
		newhouse->next=last;
		newhouse->prev=first;
		first->next->prev=newhouse;
		first->next=newhouse;
	}else{
		Node* tmp=first->next;
		
		while(tmp->x < x){
			tmp=tmp->next;
		}
		
		//把node都插在tmp的前面
		newhouse=(Node*)malloc(sizeof(Node));
		newhouse->x=x;
		newhouse->next=tmp;
		newhouse->prev=tmp->prev;
		tmp->prev->next=newhouse;
		tmp->prev=newhouse;
	}
}
void bomb(long long lower,long long upper){
	Node* now=first->next;
	while(now!=last){
		if(lower <= now->x && now->x <= upper){
			Node* tmp=now;
			now=now->prev;  //now先移到前面一個node
			now->next=tmp->next;
			tmp->next->prev=now;
			free(tmp);
		}
		now=now->next;
	}
}
void printfront(){
	printf("PrintFront\n");
	Node* it=first->next;
	while(it!=last){
		printf("%lld\n",it->x);
		it=it->next;
	}
}
void printend(){
	printf("PrintEnd\n");
	Node* it=last->prev;
	while(it!=first){
		printf("%lld\n",it->x);
		it=it->prev;
	}
}
