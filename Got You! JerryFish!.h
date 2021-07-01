#include<stdlib.h>
typedef struct node{
	int val;
	struct node* next;
}Node;

void createLinkedList(Node **head,int N,int *arr);
void swapTwoSegment(Node **head,int a,int b,int len);

void createLinkedList(Node** head,int N,int *arr)
{
	int i;
	Node* tmp;	//為了方便讓前一個node跟後一個node接起來
	for(i=1;i<=N;i++){	//注意arr[]是從1開始
		Node* newnode=(Node*)malloc(sizeof(Node));
		newnode->val=arr[i];
		if(i==1){
			tmp=newnode;
			*head=newnode;
		}else{
			tmp->next=newnode;	//接起前後node 
			tmp=newnode;	//將tmp移到目前的node上面 
		}
	}
	tmp->next = *head;	//要將最後一個node跟head接起來，形成circular linked list
}
void swapTwoSegment(Node** head,int a,int b,int len)
{
	int i;
	//從head出發
	Node* one = *head;
	Node* two = *head;
	
	//移動
	while(--a){
		one=one->next;
	}
	while(--b){
		two=two->next;
	}
	
	for(i=0;i<len;i++){
		//交換
		int tmp=one->val;
		one->val=two->val;
		two->val=tmp;
		
		//移動到下一個node
		one=one->next;
		two=two->next;
	}
}
