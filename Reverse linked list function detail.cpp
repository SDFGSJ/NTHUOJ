#include <stdio.h>
#include <stdlib.h>

typedef struct _Node{
    int data;
    struct _Node* next;
} Node;


void Push(Node** ptr_head, int x);
void Pop(Node** ptr_head);
void Reverse_List(Node** ptr_head);

void Push(Node** ptr_head,int x)
{
	Node *temp=*ptr_head;
	*ptr_head=(Node*)malloc(sizeof(Node));
	(*ptr_head)->next=temp;
	(*ptr_head)->data=x;
}
void Pop(Node** ptr_head)
{
	if( (*ptr_head)!=NULL ){
		Node *temp=*ptr_head;
		*ptr_head=(*ptr_head)->next;
		free(temp);
	}else{
		return;
	}
	
}
void Reverse_List(Node** ptr_head)
{
	Node *temp=*ptr_head;
	Node *pre=NULL;
	while( (*ptr_head)!=NULL )
	{
		*ptr_head=(*ptr_head)->next;
		temp->next=pre;
		pre=temp;
		temp=*ptr_head;
	}
	*ptr_head=pre;
}
