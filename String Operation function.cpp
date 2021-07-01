#include<iostream>
#include<cstring>
using namespace std;

class Char{
friend class Str;
private:
	Char(char text):next(NULL){
		this->text=text;
	}

	~Char(){
        if(next)
            delete next;
	}

	void print(){
        cout<<text;
        if(next)
            next->print();
	}

	char text;
	Char *next;
};

class Str{
public:
	Str():head(NULL),tail(NULL){}
	Str(char*); // construct a new Str by linked list of Char
	Str(const Str &); // copy constructor
	
	~Str(){
        if(head)
            delete head;
	}

	Str& strInsert(const Str&);

	Str& strSwap(Str& s){
		Str* tmp=new Str(*this);
		this->~Str();

		*this=s;
        s=*tmp;

        tmp->head=NULL;
        delete tmp;
		return *this;
	}

	void strPrint(){
        if(head)
            head->print();
        cout<<endl;
	}

private:
	Char* head;
	Char* tail;
};

Str::Str(char* str){	// construct a new Str by linked list of Char
	int i;
	int len=strlen(str);
	Char *tmp=NULL,*now=NULL;
	for(i=len-1;i>=0;i--){	//從尾巴開始建list
		now=new Char(str[i]);
		now->next=tmp;
		tmp=now;
		if(i==len-1){	//這邊是兩個if，要小心只有一個字的情況
			tail=now;
		}
		if(i==0){
			head=now;
		}
	}
}
Str::Str(const Str& str){	// copy constructor
	Char *now=str.head,*tmp=NULL;
	head=tail=NULL;
	while(now!=NULL){	//從頭抄到尾
		if(head==NULL){
			head=new Char(now->text);
			tmp=tail=head;
		}else{
			tail=new Char(now->text);
			tmp->next=tail;
			tmp=tail;
		}
		now=now->next;
	}
	tail->next=NULL;
}

Str& Str::strInsert(const Str& str){
	/*Str back=str;*/	//這裡不能這樣寫是因為back在離開這個函式時會呼叫destructor，讓指標被delete掉從而造成memory leak
	
	Str* back=new Str(str);	//new一個str讓它一直存在
	tail->next=back->head;
	tail=back->tail;
	return *this;
}
