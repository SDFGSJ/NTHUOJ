#include <iostream>
/* an abstract class for the container used in this problem */
class ContainerBase {
public:
	/* for the first-type operation */
	virtual int print() = 0;
	/* for the second-type operation */
	virtual void move(int) = 0;
	/* for the third-type operation */
	virtual void remove() = 0;
	int getSize() { return size; }

	virtual ~ContainerBase() {}
protected:
	int size;	// the number of elements(people) in the container
};

/* array class deriving from ContainerBase */
class Array final : public ContainerBase {
public:
	Array() {}
	Array(int n, int *arr) {
		size = n;
		
		mem = new int[size + 1];
		for(int i=1;i<=size;i++)	mem[i] = arr[i];
		cur = 1;
	}
	
	virtual int print() override { return mem[cur]; }
	/* TODO */
	virtual void move(int) override;
	/* TODO */
	virtual void remove() override;
	
	~Array() { delete[] mem; }
private:
	int *mem;	// array for maintaining all the elements(the happy value of all the people)
	int cur;	// record who is carrying the ball
};

/* doubly linked list class deriving from ContainerBase */
class List final : public ContainerBase {
public:
	List() {}
	List(int n, int *arr) {
		size = n;
		
		cur = new Node(arr[1]);
		Node *back = cur;
		for(int i=2;i<=n;i++) {
			Node *newNode = new Node(arr[i]);
			back->insertBack(newNode);
			back = newNode;
		}
	}
	
	virtual int print() override { return cur->getVal(); }
	/* TODO */
	virtual void move(int) override;
	/* TODO */
	virtual void remove() override;
	
	~List() { for(int i=1;i<=size;i++)	cur = cur->remove(); }
private:
	/* nested class for the node in linked list */
	class Node {
		public:
			Node() {}
			Node(int newVal) : pre(nullptr), nxt(nullptr), val(newVal) {}
			/* insert a new node after the current node */
			void insertBack(Node *newNode) {
				nxt = newNode;
				newNode->pre = this;
			}
			/* remove the current node and return the next node(or the previous node if the next node doesn't exist) */
			Node* remove() {
				Node *ret = (nxt == nullptr ? pre : nxt);
				if(pre != nullptr)	pre->nxt = nxt;
				if(nxt != nullptr)	nxt->pre = pre;
				delete this;
				return ret;
			}
			Node* getPre() { return pre; }
			Node* getNxt() { return nxt; }
			int getVal() { return val; }
		private:
			Node *pre, *nxt;
			int val;
	} *cur;	// record who is carrying the ball
};

/* a class for operation */
class Operation {
public:
	int type,d;
};

/* TODO: create array/linked list based on operations and return it */
ContainerBase* create(int, int*, int, Operation*);

using namespace std;
int main() {
	/* I/O optimization */
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int t;
	cin >> t;
	while(t--) {
		int n;
		cin >> n;
		int *arr = new int[n + 1];
		for(int i=1;i<=n;i++)	cin >> arr[i];
		
		int q;
		cin >> q;
		Operation *ops = new Operation[q + 1];
		for(int i=1;i<=q;i++) {
			cin >> ops[i].type;
			if(ops[i].type == 2)
				cin >> ops[i].d;
		}

		ContainerBase* solver = create(n, arr, q, ops);
		for(int i=1;i<=q;i++) {
			if(ops[i].type == 1)
				cout << solver->print() << '\n';
			else if(ops[i].type == 2)
				solver->move(ops[i].d);
			else
				solver->remove();
		}

		delete[] arr;
		delete[] ops;
		delete solver;
	}
	printf("----------------\n");
	return 0;
}
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
	for(i=cur;i<size;i++){
		mem[i]=mem[i+1];
	}
	if(cur==size){
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
	cur=cur->remove();
	size--;
}

/*create array/linked list based on operations and return it */
ContainerBase* create(int n,int* ar,int q,Operation* op){
	int i;
	int two=0,three=0;
	ContainerBase* c=nullptr;
	for(i=1;i<=q;i++){
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
