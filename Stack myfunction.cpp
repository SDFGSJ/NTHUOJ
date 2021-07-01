#include<cstdio>
#include<cstdlib>
class ListNode
{
friend class List_stack;

public:
    ListNode(const int& info):data(info),nextPtr(NULL),prevPtr(NULL){}
private:
    int data;
    ListNode *nextPtr,*prevPtr;
};

class List_stack
{
public:
    List_stack();
    ~List_stack();
    void push(const int&);
    void pop();
    void print();
private:
    ListNode *head,*tail;
};


List_stack::List_stack(){
	head=tail=NULL;
}
List_stack::~List_stack(){
	ListNode *now=head,*tmp=head;
	while(now!=NULL){
		now=now->nextPtr;
		free(tmp);
		tmp=now;
	}
	head=tail=NULL;
}
void List_stack::push(const int& n){
	ListNode* node=(ListNode*)malloc(sizeof(ListNode));
	node->data=n;
	
	if(head==NULL){	//如果是第一個node
		head=tail=node;
		node->prevPtr = node->nextPtr = NULL;
	}else{	//如果有其他node
		node->prevPtr=tail;
		tail->nextPtr=node;
		
		node->nextPtr=NULL;
    	tail=node;
	}
}
void List_stack::pop(){
	if(head==tail){	//如果只有一個node
		free(tail);
		head=tail=NULL;
	}else if(tail!=NULL){
    	tail=tail->prevPtr;
    	free(tail->nextPtr);
    	tail->nextPtr=NULL;
	} 
}
void List_stack::print(){
	ListNode* now=tail;
	while(now!=NULL){
		if(now==tail)	printf("%d",now->data);
		else	printf(" %d",now->data);
		now=now->prevPtr;
	}
}

