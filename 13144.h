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
    	//�M���Ӧ椧����empty || �@�}�l��empty���A
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
		}else{	//�p�G�Ӧ�O�Ū��N���Nqueue[0]�]��' '�Areturn��
			_queue[0]=' ';
			return _queue[0];
		}
	}

    void push(const T& item){
    	if(_rear==capacity){	//�p�Gqueue�w�g���F
    		T* temp=_queue;	//���O���queue����}
    		_queue=new T[2*capacity];	//�A�h�n�@�Ө⭿�j��queue
    		
    		int i;
    		for(i=0;i<capacity;i++){	//�ۤ��e
    			_queue[i]=temp[i];
			}
			
			capacity*=2;	//��scapacity
		}
		//printf("before:(front,rear)=(%d,%d)\n",_front,_rear);
		_queue[_rear++]=item;
		if(this->_front==-1){	//�p�G�o�椰�򳣨S���A�N��s_front����=0
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
	
	/*���X�b[start,start+len-1]�������̰����סA�H�M�w�n�ɦh�֭�'@'*/
	int max_h=-1;
	for(i=start;i<=start+len-1;i++){
		if(height[i]>max_h)
			max_h=height[i];
	}
	/*printf("[%d,%d]max_h=%d\n",start,start+len-1,max_h);*/
	
	for(i=start,idx=0 ; i<start+len && idx<len ; i++,idx++){
		/*printf("max_h=%d,height[%d]=%d\n",max_h,i,height[i]);*/
		int diff=max_h-height[i];	//�̰����׻P�Ӧ檺���׮t
		while(diff--){
			/*printf("%d-th col insert @\n",i);*/
			myqueue[i].push('@');
			height[i]++;	//height[]�O�o��s
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
	return s;	//�^�ǪŦr��
}
void query(int L)
{
	int i,j;
	
	string q;
	cin>>q;
	int len=q.length();
	
	//���r��
	bool same=true;
	for(i=0;i<=L-len;i++){
		same=true;	//���]�C�@���}�l���Otrue
		for(j=0;j<len;j++){
			if(myqueue[i+j].front()!=q[j]){
				same=false;
				break;
			}
		}
		//�p�G�r��۵��N�����~���F
		if(same){
			break;
		}
	}
	
	/*printf("-------------\n");
	printf("starting place=%d\n",i);*/
	
	if(same){
		string card;
		//��J�r�ñNbottom_row�M���A�O�o��sheight
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
	//�M��myqueue
	for(i=0;i<L;i++){	
		while(!myqueue[i].empty()){
			myqueue[i].pop();
		}
		height[i]=0;
	}
	//�M��mystack
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
