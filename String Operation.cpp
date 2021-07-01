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
	Char* next;
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
		Str *tmp=new Str(*this);
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

int main(){
	int N;
	char input[100];

	int index=0;
	Str* s[100];

	cin>>N;
    for(int i=0;i<N;i++){
    	cin>>input;
    	s[index++]=new Str(input);
    }

    char op[3];	//"si" || "is" || "s" || "i" || "e"
    while(1){
    	cin>>op;
    	if(op[0]=='e')break;

    	int idx1,idx2;
    	cin>>idx1;
    	cin>>idx2;

    	Str& s1= *s[idx1];
    	Str& s2= *s[idx2];


        if(op[0]=='s'&&op[1]=='i'){
            s1.strSwap(s2).strInsert(s2);

        }else if(op[0]=='i'&&op[1]=='s'){
            s1.strInsert(s2).strSwap(s2);

        }else if(op[0]=='s'){
            s1.strSwap(s2);

        }else if(op[0]=='i'){
            s1.strInsert(s2);

        }
        /*printf("after:\n");
        for(int i=0;i<N;i++){
	        s[i]->strPrint();
		}
		printf("\n");*/
	}

	for(int i=0;i<N;i++){
        s[i]->strPrint();
        delete s[i];
	}

	return 0;
}
Str::Str(char* str){	// construct a new Str by linked list of Char
	int i;
	int len=strlen(str);
	Char *tmp=NULL,*now=NULL;
	for(i=len-1;i>=0;i--){
		now=new Char(str[i]);
		now->next=tmp;
		tmp=now;
		if(i==len-1){
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
	while(now!=NULL){
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
	Str* back=new Str(str);	//先做新的一個str
	this->tail->next=back->head;
	this->tail=back->tail;
	return *this;
}
