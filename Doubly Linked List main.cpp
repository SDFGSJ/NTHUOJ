#include <iostream>
#include<cstdio>
#include <string>
#include <stdexcept>
using namespace std;

class ListNode{
private:
    int data;
    ListNode *next;
    ListNode *prev;
public:
    ListNode():data(0),next(nullptr),prev(nullptr){};
    ListNode(int a):data(a),next(nullptr),prev(nullptr){};

friend class List;
};

class List{
private:
    ListNode* head;  // head of the doubly linked list
    ListNode* tail;  // tail of the doubly linked list
    ListNode* middle; // middle of the list
    int       cnt;   // total count of the elements in the list
    int       pos;   // the position of middle

    void reset(){
        head = nullptr;
        tail = nullptr;
        middle = nullptr;
        cnt = 0;
        pos = 0;
    }

    void clean(){
        ListNode* temp;
        while(head!=nullptr){
        	//printf("a\n");
            temp = head;
            head = head->next;
            delete temp;
        }
    }
	
public:
    // constructor and destructor
    List(){
        reset();
    }

    ~List(){
        clean();
    }
	void print(){
		printf("List=");
		ListNode* now=head;
		while(now!=nullptr){
			printf("%d,",now->data);
			now=now->next;
		}
		printf("\n");
	}
    void InsertHead(int data);
    int  RemoveHead();
    void InsertTail(int data);
    int  RemoveTail();
    void Swap();
    int  getSize();
    int  getMiddle();
};

int main(){
    List L;
    string cmd;
    int data, cnt=0, pos = 0;

    while(cin >> cmd){
        if(cmd=="IH"){ // insert an integer to the head
            cin >> data;
            L.InsertHead(data);
        } else if (cmd=="IT"){ // insert an integer to the end
            cin >> data;
            L.InsertTail( data);
        } else if (cmd=="RH"){   // print and remove a node from head
            try {
                cout<< L.RemoveHead() <<endl;
            } catch (const out_of_range &e){
                cout << endl;
            }
        } else if (cmd=="RT") {// print and remove a node from tail
            try {
                cout << L.RemoveTail()<<endl;
            } catch (const out_of_range &e){
                cout << endl;
            }
        } else if (cmd=="S"){
            L.Swap();
        }
        //L.print();
    }
}
void List::InsertHead(int data){
	if(head==nullptr){	//如果是第一個node
		head=new ListNode(data);
		middle=tail=head;
		head->prev=head->next=nullptr;
		pos=1;
	}else{
		ListNode* tmp=head;
		head=new ListNode(data);
		head->next=tmp;
		tmp->prev=head;
		head->prev=nullptr;
	}
	
	cnt++;
	pos++;
	if(pos > cnt/2+1){
		pos--;
		middle=middle->prev;
	}
}
int List::RemoveHead(){
	if(head!=nullptr){
		cnt--;
		pos--;
		if(pos < cnt/2+1){
			pos++;
			middle=middle->next;
		}
		
		ListNode* tmp=head;
		int n=tmp->data;
		if(head==tail){	//如果只有一個node
			reset();	//前面要先維護好middle才可以在這邊reset
		}else{
			head=head->next;
			head->prev=nullptr;
		}
		
		delete tmp;
		return n;
	}else{
		throw std::out_of_range("\n");
	}
}
void List::InsertTail(int data){
	if(tail==nullptr){	//如果只有一個node
		head=new ListNode(data);
		middle=tail=head;
		head->prev=head->next=nullptr;
		pos=1;
	}else{
		ListNode* tmp=tail;
		tail=new ListNode(data);
		tail->prev=tmp;
		tmp->next=tail;
		tail->next=nullptr;
	}
	
	cnt++;
	if(pos < cnt/2+1){
		pos++;
		middle=middle->next;
	}
}
int List::RemoveTail(){
	if(tail!=nullptr){
		cnt--;
		if(pos > cnt/2+1){
			pos--;
			middle=middle->prev;
		}
		
		ListNode* tmp=tail;
		int n=tmp->data;
		if(head==tail){
			reset();
		}else{
			tail=tail->prev;
			tail->next=nullptr;
		}
		delete tmp;
		return n;
	}else{
		throw std::out_of_range("\n");
	}
}
void List::Swap(){	//要更新middle
	if(cnt==0 || cnt==1)	return;
	
	if(head!=nullptr && tail!=nullptr){
		ListNode* newtail=middle->prev;	//middle的前一個node當新的tail
		tail->next=head;
		head->prev=tail;
		middle->prev = newtail->next = nullptr;
		
		head=middle;	//注意這三者的順序
		middle=tail;
		tail=newtail;
	}
	
	if(cnt%2==0){	//如果是偶數個node就要微調middle，奇數不用
		middle=middle->next;
	}
}
int List::getSize(){
	return cnt;
}
int List::getMiddle(){
	return pos;
}
