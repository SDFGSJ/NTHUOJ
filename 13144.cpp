#include<iostream>
#include<string>
#include<cstdio>
using namespace std;

template<class T>
class BaseStack
{
public:
    //Constructor
    BaseStack(){
    	_stack=new T[10005];
    	capacity=10005;
    	_top=-1;
	}

    //Destructor
    ~BaseStack(){
    	delete [] _stack;
    	capacity=0,_top=-1;
	}

    //Check if the stack is empty
    bool empty(){
    	return _top==-1;
	}

    //Return the size of the stack
    int size(){
    	return _top+1;
	}

    //Return the top element
    T& top(){
    	if(!empty()){
    	//printf("_top=%d\n",_top);
    		return _stack[_top];
		}
	}

    //Insert a new element at top
    void push(const T& item){
		_stack[++_top]=item;
	}

    //Delete one element from top
    void pop(){
    	if(!empty()){
	    	_stack[_top--].~T();
		}
	}

private:
    T* _stack;
    int _top;
    int capacity;
};

template<class T>
class BaseQueue
{
public:
    //Constructor   
    BaseQueue(){
    	_queue=new T[100005];
    	capacity=100005;
    	_front=-1;
    	_rear=0;
	}
    
    //Destructor
    ~BaseQueue(){
    	delete [] _queue;
    	capacity=0,_front=-1,_rear=0;
	}

    //Check if the queue is empty
    bool empty(){
    	return _front==_rear || (_front==-1 && _rear==0);
	}

    //Return the size of the queue
    int size(){
    	return _rear-_front+1;
	}

    //Return the front element
    T& front(){
    	if(!empty()){
    		return _queue[_front];
		}else{
			_queue[0]=' ';
			return _queue[0];
		}
	}

    //Insert a new element at rear
    void push(const T& item){
    	if(_rear==capacity){
    		T* temp=_queue;
    		_queue=new T[2*capacity];
    		int i;
    		for(i=0;i<capacity;i++){
    			_queue[i]=temp[i];
			}
			capacity*=2;
		}
		//printf("before:(front,rear)=(%d,%d)\n",_front,_rear);
		_queue[_rear++]=item;
		if(this->_front==-1){
			this->_front=0;
		}
		//printf("after:(front,rear)=(%d,%d)\n-------------------\n",_front,_rear);
	}

    //Delete one element from front
    void pop(){
    	if(!empty()){
    		_queue[_front++].~T();
		}
	}

private:
    T* _queue;
    int _front, _rear;
    int capacity;
};

BaseQueue<char> myqueue[105];
BaseStack<string> mystack;

int height[105];

void insert(int L)
{
	int i,idx;
	
	int start;
	string insert_str;
	cin >> start >> insert_str;
	int len=insert_str.length();
	
	int max_h=-1;
	/*取出在[start,start+len-1]之間的最高高度*/
	for(int k=start;k<=start+len-1;k++){
		if(height[k]>max_h)	max_h=height[k];
	}
	/*printf("[%d,%d]max_h=%d\n",start,start+len-1,max_h);*/
	
	for(i=start,idx=0 ; i<start+len && idx<len ; i++,idx++){
		/*printf("max_h=%d,height[%d]=%d\n",max_h,i,height[i]);*/
		int diff=max_h-height[i];
		while(diff--){
			/*printf("%d-th col insert @\n",i);*/
			myqueue[i].push('@');
			height[i]++;
		}
		/*printf("-->insert %c\n",insert_str[idx]);*/
		myqueue[i].push(insert_str[idx]);
		height[i]++;
	}
	/*cout<<"height[i]=";
	for(i=0;i<L;i++){
		cout<<height[i]<<",";
	}
	cout<<"\n";*/
}
string first_row(int L, bool print)
{
	int i;
	string s="";
	cout<<"BOTTOM_ROW"<<"\n";
	
	for(i=0;i<L;i++){
		if(!myqueue[i].empty()){
			cout<<myqueue[i].front();
		}else{
			cout<<'~';
		}
	}
	cout<<"\n";
	return s;
}
void query(int L)
{
	int i,j;
	
	string q;
	cin>>q;
	int len=q.length();
	
	
	bool same=true;
	for(i=0;i<=L-len;i++){
		same=true;
		for(j=0;j<len;j++){
			
			if(myqueue[i+j].front()!=q[j]){
				same=false;
				break;
			}
		}
		if(same){
			break;
		}
	}
	
	/*printf("-------------\n");
	printf("starting place=%d\n",i);*/
	
	if(same){
		string card;
		for(j=0;j<len;j++){
			/*printf("word removed:%c\n",myqueue[i+j].front());*/
			card.push_back(myqueue[i+j].front());
			myqueue[i+j].pop();
			height[i+j]--;
		}
		mystack.push(card);
		/*cout<<"card="<<card<<"\n";
		cout<<"top of mystack="<<mystack.top()<<"\n";
		for(i=0;i<L;i++){
			if(myqueue[i].front()==' '){
				printf("~");
			}else{
				printf("%c",myqueue[i].front());
			}
		}
		printf("\n-----------------\n");*/
	}
}
void flush()
{
	cout<<"FLUSH"<<"\n";
	while(!mystack.empty()){
		cout<<mystack.top()<<"\n";
		mystack.pop();
	}
}
void reset(int L)
{
	int i;
	for(i=0;i<L;i++){	
		while(!myqueue[i].empty()){
			myqueue[i].pop();
		}
		height[i]=0;
	}
	while(!mystack.empty()){
		mystack.pop();
	}
	//printf("mystack's size=%d\n",mystack.size());
}

int main(void){
    int L,C;
    string command;
    
    cin >> L >> C;
    
    for (int i=0;i<C;i++) {
        cin >> command;

        if(command=="INSERT"){
            insert(L);
        }else if(command=="BOTTOM_ROW"){
            first_row(L,true);
        }else if(command=="QUERY"){
            query(L);
        }else if(command=="FLUSH"){
            flush();
        }else if(command=="RESET"){
            reset(L);
        }
    }
}

