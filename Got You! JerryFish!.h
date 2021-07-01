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
	Node* tmp;	//���F��K���e�@��node���@��node���_��
	for(i=1;i<=N;i++){	//�`�Narr[]�O�q1�}�l
		Node* newnode=(Node*)malloc(sizeof(Node));
		newnode->val=arr[i];
		if(i==1){
			tmp=newnode;
			*head=newnode;
		}else{
			tmp->next=newnode;	//���_�e��node 
			tmp=newnode;	//�Ntmp����ثe��node�W�� 
		}
	}
	tmp->next = *head;	//�n�N�̫�@��node��head���_�ӡA�Φ�circular linked list
}
void swapTwoSegment(Node** head,int a,int b,int len)
{
	int i;
	//�qhead�X�o
	Node* one = *head;
	Node* two = *head;
	
	//����
	while(--a){
		one=one->next;
	}
	while(--b){
		two=two->next;
	}
	
	for(i=0;i<len;i++){
		//�洫
		int tmp=one->val;
		one->val=two->val;
		two->val=tmp;
		
		//���ʨ�U�@��node
		one=one->next;
		two=two->next;
	}
}
