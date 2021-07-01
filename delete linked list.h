#include <stdlib.h>
#include <stdio.h>

typedef struct _Node {
    int data;
    struct _Node *next;
} Node;

void deleteNode(Node ** nd, int data);
Node* createList();
Node* createList()
{
	int num;
	Node *now=NULL,*head=NULL,*temp=NULL;
	while(1)
	{
		scanf("%d",&num);
		if(num>-1){
			now=(Node*)malloc(sizeof(Node));
			now->data=num;
			if(temp!=NULL){
				temp->next=now;
				temp=now;
			}else{
				temp=now;
				head=now;
			}
		}else{
			now->next=NULL;	//如果讀到-1就要幫list做結尾 
			break;
		}
	}
	return head;
}
void deleteNode(Node ** nd, int data)
{
	Node *temp=*nd;
	Node *now=*nd;
	if(data==1 && (*nd)!=NULL){
		(*nd)=(*nd)->next;
		free(temp);
	}else{
		while(--data && now->next!=NULL)
		{
			temp=now;
			now=now->next;
		}
		if(now->next==NULL && data==0){
			temp->next=NULL;
			free(now);
		}else if(now->next==NULL && data!=0){
			return;
		}else if(now->next!=NULL/* && data==0*/){
			temp->next=now->next;
			free(now);
		}
	}
}
