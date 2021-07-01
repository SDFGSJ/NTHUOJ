#include "function.h"

void Array::move(int d) {
	if(cur+d<1){
		cur=1;
	}else if(size<cur+d){
		cur=size;
	}else{
		cur+=d;
	}
}

void Array::remove() {
	int i;
	for(i=cur;i<size;i++){	//如果cur是在中間就不用特別調整cur後來的位置，因為將資料往前搬移就已經讓cur指到原本的後一位
		mem[i]=mem[i+1];
	}
	if(cur==size){	//如果cur是最後一個就要把它移到它的前一個人
		cur--;
	}
	size--;
}

void Array::reverse() {
	int a;
}

void List::move(int d) {
	if(d>0){	//moving right
		while(cur->nxt!=nullptr && d>0){
			cur=cur->nxt;
			d--;
		}
	}else{	//moving left
		while(cur->pre!=nullptr && d<0){
			cur=cur->pre;
			d++;
		}
	}
}

void List::remove() {
	cur=cur->remove();	//remove函式已經調整好cur
	size--;
}

void List::reverse() {
	int a;
}

ContainerBase* create(int n, int *arr, int op2Cnt, int op3Cnt) {
	int i;
	ContainerBase* c=nullptr;
	if(op2Cnt>op3Cnt){	//array
		c=new Array(n,arr);
	}else{	//linked list
		c=new List(n,arr);
	}
	return c;
}
