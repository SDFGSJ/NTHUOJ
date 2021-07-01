#include"function.h"
void _stack::push(const _node N){
	_node* newnode=new _node(N);
	newnode->next=End;
	newnode->prev=End->prev;
	End->prev->next=newnode;
	End->prev=newnode;
}
void _stack::pop(){
	if(Begin->next==End && End->prev==Begin){
		return;
	}
	_node* tmp=End->prev;
	tmp->prev->next=tmp->next;
	tmp->next->prev=tmp->prev;
	delete tmp;
}
_node* _stack::get_data(){
	if(End->prev==Begin){
		return NULL;
	}else{
		return End->prev;
	}
}
void _queue::push(const _node N){
	_node* newnode=new _node(N);
	newnode->next=End;
	newnode->prev=End->prev;
	End->prev->next=newnode;
	End->prev=newnode;
}
void _queue::pop(){
	if(Begin->next==End && End->prev==Begin){
		return;
	}
	_node* tmp=Begin->next;
	tmp->prev->next=tmp->next;
	tmp->next->prev=tmp->prev;
	delete tmp;
}
_node* _queue::get_data(){
	if(Begin->next==End){
		return NULL;
	}else{
		return Begin->next;
	}
}
