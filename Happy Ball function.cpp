#include"function.h"
void Array::move(int n){
	if(cur+n<1){
		cur=1;
	}else if(size<cur+n){
		cur=size;
	}else{
		cur+=n;
	}
}

void Array::remove(){
	int i;
	for(i=cur;i<size;i++){	//�p�Gcur�O�b�����N���ίS�O�վ�cur��Ӫ���m�A�]���N��Ʃ��e�h���N�w�g��cur����쥻����@��
		mem[i]=mem[i+1];
	}
	if(cur==size){	//�p�Gcur�O�̫�@�ӴN�n�⥦���쥦���e�@�ӤH
		cur--;
	}
	size--;
}

void List::move(int n){
	if(n>0){	//moving right
		while(cur->getNxt()!=nullptr && n>0){
			cur=cur->getNxt();
			n--;
		}
	}else{	//moving left
		while(cur->getPre()!=nullptr && n<0){
			cur=cur->getPre();
			n++;
		}
	}
}

void List::remove(){
	cur=cur->remove();	//remove�禡�w�g�վ�ncur
	size--;
}

/*create array/linked list based on operations and return it */
ContainerBase* create(int n,int* ar,int q,Operation* op){
	int i;
	int two=0,three=0;
	ContainerBase* c=nullptr;
	for(i=1;i<=q;i++){	//�p��op type���`�ƥH�M�w�ϥέ��Ӹ�Ƶ��c����n
		if(op[i].type==2){
			two++;
		}else if(op[i].type==3){
			three++;
		}
	}
	if(two>three){	//array
		c=new Array(n,ar);
	}else{	//linked list
		c=new List(n,ar);
	}
	return c;
}
