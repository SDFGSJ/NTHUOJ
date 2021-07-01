#include<stdlib.h>
typedef struct node{
	struct node* next;
	int val;
}Node;

void createLinkedList(Node **head,int N,int *arr);
void swapTwoSegment(Node **head,int N,int a,int b,int len);

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
		if( (b+len-1)%N >= a || b+len-1>=a )	return;	//�n�`�Nb+len-1��n����N�����ΡA�p�G%N���|��0�A�ҥH�n�h�[�@��or�P�_
		if( (a+len-1)>=N && (a+len-1)%N >= b)	return;	
	}else if(a<b){
		if( (a+len-1)%N >= b || a+len-1>=b )	return;	//�n�`�Na+len-1��n����N�����ΡA�p�G%N���|��0�A�ҥH�n�h�[�@��or�P�_
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
