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
	for(i=cur;i<size;i++){	//如果cur是在中間就不用特別調整cur後來的位置，因為將資料往前搬移就已經讓cur指到原本的後一位
		mem[i]=mem[i+1];
	}
	if(cur==size){	//如果cur是最後一個就要把它移到它的前一個人
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
	cur=cur->remove();	//remove函式已經調整好cur
	size--;
}

/*create array/linked list based on operations and return it */
ContainerBase* create(int n,int* ar,int q,Operation* op){
	int i;
	int two=0,three=0;
	ContainerBase* c=nullptr;
	for(i=1;i<=q;i++){	//計算op type的總數以決定使用哪個資料結構比較好
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
