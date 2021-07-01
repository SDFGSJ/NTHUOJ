#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<string>
using namespace std;
struct Node{
	long long x,y;
	Node *next,*prev;
};
Node *first,*last,*d_head,*d_tail;
void house(long long,long long);
void bomb(long long,long long);
void printfront();
void printend();
int main(){
	int t;
	scanf("%d",&t);
	
	//initialize dummy node
	d_head=(Node*)malloc(sizeof(Node));
	d_tail=(Node*)malloc(sizeof(Node));
	d_head->x = d_head->y = 1e11;
	d_head->next = d_tail;
	
	d_tail->x = d_tail->y = 1e11;
	d_tail->prev = d_head;
	
	first=d_head;
	last=d_tail;
	
	while(t--){
		string command;
		cin>>command;
		if(command=="House"){
			long long a,b;
			scanf("%lld%lld",&a,&b);
			house(a,b);
		}else if(command=="Bomb"){
			long long a,b;
			scanf("%lld%lld",&a,&b);
			bomb(a,b);
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
void house(long long x,long long y){
	Node *newhouse=NULL,*it;
	
	//檢查一下x,y是否已經有房子
	int exist=0;
	for(it=first->next;it!=last;it=it->next){
		if(it->x==x && it->y==y){
			exist=1;
		}
	}
	if(exist) return;
	
	if(first->next==last){  //如果插入的是第一個node
		newhouse=(Node*)malloc(sizeof(Node));
		newhouse->x=x;
		newhouse->y=y;
		newhouse->next=last;
		newhouse->prev=first;
		first->next->prev=newhouse;
		first->next=newhouse;
	}else{
		Node* tmp=first->next;
		
		while(tmp->y < y){
			tmp=tmp->next;
		}
		while(tmp->x < x && tmp->y <= y){   //注意是<=y
			tmp=tmp->next;
		}
		
		//把node都插在tmp的前面
		newhouse=(Node*)malloc(sizeof(Node));
		newhouse->x=x;
		newhouse->y=y;
		newhouse->next=tmp;
		newhouse->prev=tmp->prev;
		tmp->prev->next=newhouse;
		tmp->prev=newhouse;
	}
}
void bomb(long long x,long long y){
	Node* now=first->next;
	while(now!=last){
		if((now->x==x && now->y==y) || (now->x==x+1 && now->y==y) || (now->x==x-1 && now->y==y) || (now->x==x && now->y==y+1) || (now->x==x && now->y==y-1)){
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
		printf("(%lld,%lld)\n",it->x,it->y);
		it=it->next;
	}
}
void printend(){
	printf("PrintEnd\n");
	Node* it=last->prev;
	while(it!=first){
		printf("(%lld,%lld)\n",it->x,it->y);
		it=it->prev;
	}
}
