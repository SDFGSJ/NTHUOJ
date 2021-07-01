#include<stdio.h>
#include<stdlib.h>
#define MAXN 100005
typedef struct node{
	struct node* next;
	int val;
}Node;

void createLinkedList(Node** head,int N,int *arr);
void swapTwoSegment(Node** head,int a,int b,int len);

int arr[MAXN];

int main(void){
	int N;
	scanf("%d",&N);
	for(int i=1;i<=N;i++)	//�`�Narr[]�O�q1�}�l
		scanf("%d",&arr[i]);
	
	Node *head=NULL;
	createLinkedList(&head,N,arr);	//malloc N��node 
	
	int Q;
	scanf("%d",&Q);
	for(int i=1;i<=Q;i++){
		int a,b,len;
		scanf("%d%d%d",&a,&b,&len);
		swapTwoSegment(&head,a,b,len);
	}

	for(int i=1;i<=N;i++){
		if(i>1)	printf(" ");
		printf("%d",head->val);
		head=head->next;
	}
	printf("\n");
	return 0;
}
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
