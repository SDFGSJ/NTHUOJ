#include<iostream>
#include<string>
class Node{
	private:
		char instrm;
		Node *neighbors[2];
		/* disconnect the link with a specific node */
		void unLink(Node *delNeighbor) {
			if(neighbors[0] == delNeighbor) neighbors[0] = nullptr;
			if(neighbors[1] == delNeighbor) neighbors[1] = nullptr;
		}
	public:
		Node() {}
		Node(char instrument) : instrm(instrument), neighbors{nullptr, nullptr} {}
		/* connect this node with another node */
		void link(Node *newNeighbor) {
			neighbors[(neighbors[0] == nullptr ? 0 : 1)] = newNeighbor;
		}
		void output(Node *prevNode) {
			std::cout << instrm;
			for(int i=0;i<2;i++)
				if(neighbors[i] != nullptr && neighbors[i] != prevNode)
					neighbors[i]->output(this);
		}
		/* TODO: destructor for this class */
		~Node();
};

class List {
	private:
		Node *head, *tail;	// point to the first and the last node of this linked list
	public:
		List() : head(nullptr), tail(nullptr) {}
		/* TODO: using a string to initialize this linked list */
		void init(std::string s);
		/* TODO: make this linked list be a new linked list which is merged from two linked list */
		void merge(List &front, List &back);
		void clear() { head = tail = nullptr; }
		/* TODO: exchange this linked list with another linked list; try to use std::swap! */
		void swap(List &swapList);
		/* TODO: reverse the order of this linked list */
		void reverse();
		void output() {
			if(head != nullptr) head->output(nullptr);
			std::cout << '\n';
		}
		/* TODO: destructor for this class */
		~List();
};

Node::~Node(){
	Node* now=neighbors[(neighbors[0] == nullptr ? 1 : 0)];
    if(now){	//有可能取到NULL
    	now->unLink(this);
		delete now;
	}
}
void List::init(std::string s){
	int i,len=s.length();
	
	head=new Node(s[0]);	//先建好第一個node
	tail=head;
	for(i=1;i<len;i++){
		Node* now=new Node(s[i]);
		tail->link(now);
		now->link(tail);
		tail=now;
	}
}
void List::merge(List& front,List& back){
	if(front.head==nullptr){	//前者為空
		head=back.head;
		tail=back.tail;
		return;
	}
	if(back.head==nullptr){	//後者為空
		head=front.head;
		tail=front.tail;
		return;
	}
	front.tail->link(back.head);
	back.head->link(front.tail);
	head=front.head;
	tail=back.tail;
}
void List::swap(List& swapList){
	std::swap(head,swapList.head);
	std::swap(tail,swapList.tail);
}
void List::reverse(){
	std::swap(head,tail);
}
List::~List(){
	delete head;
}
