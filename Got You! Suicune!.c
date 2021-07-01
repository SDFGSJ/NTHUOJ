#include<stdio.h>
#include<stdlib.h>
#define MAXN 100005
typedef struct node{
	int val;
	struct node* next;
}Node;

void createLinkedList(Node **head,int N,int *arr);
void swapTwoSegment(Node **head,int N,int a,int b,int len);

int arr[MAXN];
int main(){
	int N;
	scanf("%d",&N);
	for(int i=1;i<=N;i++)
		scanf("%d",&arr[i]);
	
	Node* head=NULL;
	createLinkedList(&head,N,arr);
	
	int Q;
	scanf("%d",&Q);
	for(int i=1;i<=Q;i++){
		int a,b,len;
		scanf("%d%d%d",&a,&b,&len);
		swapTwoSegment(&head,N,a,b,len);
	}

	for(int i=1;i<=N;i++){
		if(i>1)	printf(" ");
		printf("%d",head->val);
		head=head->next;
	}
	printf("\n");
	return 0;
}
void createLinkedList(Node **head,int N,int *arr)
{
	int i;
	Node* tmp;
	for(i=1;i<=N;i++){
		Node* newnode=(Node*)malloc(sizeof(Node));
		newnode->val=arr[i];
		if(i==1){
			tmp=newnode;
			*head=newnode;
		}else{
			tmp->next=newnode;
			tmp=newnode;
		}
	}
	tmp->next = *head;
}
void swapTwoSegment(Node** head,int N,int a,int b,int len)
{
	int i;
	if(a>b){
		if( (b+len-1)%N >= a || b+len-1>=a )	return;	//要注意b+len-1剛好等於N的情形，如果%N它會變0，所以要多加一個or判斷
		if( (a+len-1)>=N && (a+len-1)%N >= b)	return;	
	}else if(a<b){
		if( (a+len-1)%N >= b || a+len-1>=b )	return;	//要注意a+len-1剛好等於N的情形，如果%N它會變0，所以要多加一個or判斷
		if( (b+len-1)>=N && (b+len-1)%N >= a)	return;
	}
	Node* one = *head;
	Node* two = *head;
	
	while(--a){
		one=one->next;
	}
	while(--b){
		two=two->next;
	}
	
	for(i=0;i<len;i++){
		int tmp=one->val;
		one->val=two->val;
		two->val=tmp;
		
		one=one->next;
		two=two->next;
	}
}
