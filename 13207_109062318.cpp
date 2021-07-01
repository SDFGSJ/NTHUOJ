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
	for(i=cur;i<size;i++){	//�p�Gcur�O�b�����N���ίS�O�վ�cur��Ӫ���m�A�]���N��Ʃ��e�h���N�w�g��cur����쥻����@��
		mem[i]=mem[i+1];
	}
	if(cur==size){	//�p�Gcur�O�̫�@�ӴN�n�⥦���쥦���e�@�ӤH
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
	cur=cur->remove();	//remove�禡�w�g�վ�ncur
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
