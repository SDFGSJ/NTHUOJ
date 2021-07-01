#ifndef FUNCTION_H_
#define FUNCTION_H_
#include<iostream>
#include<string>
#include<cstdio>
using namespace std;

template<class T>
class BaseStack
{
public:
    BaseStack(){
    	_stack=new T[10005];
    	capacity=10005;
    	_top=-1;
	}

    ~BaseStack(){
    	delete [] _stack;
    	capacity=0,_top=-1;
	}

    bool empty(){
    	return _top==-1;
	}

    int size(){
    	return _top+1;
	}

    T& top(){
    	if(!empty()){
    		return _stack[_top];
		}
	}

    void push(const T& item){
		_stack[++_top]=item;
	}

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
    BaseQueue(){
    	_queue=new T[10005];
    	capacity=10005;
    	_front=-1;
    	_rear=0;
	}
    
    ~BaseQueue(){
    	delete [] _queue;
    	capacity=0,_front=-1,_rear=0;
	}

    bool empty(){
    	//清除該行之後變empty || 一開始的empty狀態
    	return (_front==_rear) || (_front==-1 && _rear==0);
	}

    int size(){
    	if(_front==-1 && _rear==0){
    		return 0;
		}else{
			return _rear-_front+1;
		}
	}

    T& front(){
    	if(!empty()){
    		return _queue[_front];
		}else{	//如果該行是空的就先將queue[0]設為' '再return它
			_queue[0]=' ';
			return _queue[0];
		}
	}

    void push(const T& item){
    	if(_rear==capacity){	//如果queue已經滿了
    		T* temp=_queue;	//先記住原queue的位址
    		_queue=new T[2*capacity];	//再去要一個兩倍大的queue
    		
    		int i;
    		for(i=0;i<capacity;i++){	//抄內容
    			_queue[i]=temp[i];
			}
			
			capacity*=2;	//更新capacity
		}
		//printf("before:(front,rear)=(%d,%d)\n",_front,_rear);
		_queue[_rear++]=item;
		if(this->_front==-1){	//如果這行什麼都沒有，就更新_front的值=0
			this->_front=0;
		}
		//printf("after:(front,rear)=(%d,%d)\n-------------------\n",_front,_rear);
	}

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
	
	/*取出在[start,start+len-1]之間的最高高度，以決定要補多少個'@'*/
	int max_h=-1;
	for(i=start;i<=start+len-1;i++){
		if(height[i]>max_h)
			max_h=height[i];
	}
	/*printf("[%d,%d]max_h=%d\n",start,start+len-1,max_h);*/
	
	for(i=start,idx=0 ; i<start+len && idx<len ; i++,idx++){
		/*printf("max_h=%d,height[%d]=%d\n",max_h,i,height[i]);*/
		int diff=max_h-height[i];	//最高高度與該行的高度差
		while(diff--){
			/*printf("%d-th col insert @\n",i);*/
			myqueue[i].push('@');
			height[i]++;	//height[]記得更新
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
	cout<<"BOTTOM_ROW\n";	
	for(i=0;i<L;i++){
		if(!myqueue[i].empty()){
			cout<<myqueue[i].front();
		}else{
			cout<<'~';
		}
	}
	cout<<"\n";
	return s;	//回傳空字串
}
void query(int L)
{
	int i,j;
	
	string q;
	cin>>q;
	int len=q.length();
	
	//比對字串
	bool same=true;
	for(i=0;i<=L-len;i++){
		same=true;	//假設每一次開始都是true
		for(j=0;j<len;j++){
			if(myqueue[i+j].front()!=q[j]){
				same=false;
				break;
			}
		}
		//如果字串相等就不用繼續比了
		if(same){
			break;
		}
	}
	
	/*printf("-------------\n");
	printf("starting place=%d\n",i);*/
	
	if(same){
		string card;
		//填入字並將bottom_row清除，記得更新height
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
	//清空myqueue
	for(i=0;i<L;i++){	
		while(!myqueue[i].empty()){
			myqueue[i].pop();
		}
		height[i]=0;
	}
	//清空mystack
	while(!mystack.empty()){
		mystack.pop();
	}
}

#endif
#ifndef vector
#define vector
#endif
#ifndef list
#define list
#endif
#ifndef forward_list
#define forward_list
#endif
#ifndef deque
#define deque
#endif
#ifndef array
#define array
#endif
#ifndef set
#define set
#endif
#ifndef multiset
#define multiset
#endif
#ifndef map
#define map
#endif
#ifndef multimap
#define multimap
#endif
#ifndef unordered_set
#define unordered_set
#endif
#ifndef unordered_multiset
#define unordered_multiset
#endif
#ifndef unordered_map
#define unordered_map
#endif
#ifndef unordered_multimap
#define unordered_multimap
#endif
#ifndef bitset
#define bitset
#endif
#ifndef valarray
#define valarray
#endif
#ifndef stack
#define stack
#endif
#ifndef queue
#define queue
#endif
#ifndef priority_queue
#define priority_queue
#endif
