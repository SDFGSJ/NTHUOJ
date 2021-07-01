#include <stdio.h>
#include <stdlib.h>
typedef struct _Node{
    int data;
    struct _Node *next;
}Node;

void printList(Node *head){
    Node *temp;
    for(temp = head; temp!=NULL; temp=temp->next) {
        printf("%d ", temp->data);
    }
}

void freeList(Node *head){
    Node *temp;
    for(temp=head; temp!=NULL; temp=head){
        head = head->next;
        free(temp);
    }
}

Node* createList();

void deleteNode(Node ** nd, int data);

int main()
{
    Node *head;
    int data;

    head = createList();
    while(1){
        scanf("%d", &data);
        if(data>-1){
            deleteNode(&head,data);
        }else break;
    }

    printList(head);
    freeList(head);
    return 0;
}
Node* createList()
{
	int num;
	Node *now=NULL,*head=NULL,*temp=NULL;
	while(1)
	{
		scanf("%d",&num);
		if(num>-1){
			now=(Node*)malloc(sizeof(Node));
			now->data=num;	//填入資料 
			if(temp!=NULL){	//如果不是第一個node 
				temp->next=now;	//將後面的node接起來 
				temp=now;	//temp移到now
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
	Node *temp=*nd;	//temp,now先記住list的開頭位置 
	Node *now=*nd;
	//刪除開頭的node要另外處理 
	if(data==1 && (*nd)!=NULL){	//如果是刪除開頭的node 
		(*nd)=(*nd)->next;	//注意動的是nd，不是now 
		free(temp);
	}else{
		while(--data && now->next!=NULL)	//注意是data-- 
		{
			temp=now;
			now=now->next;
		}
		//注意跳出while的條件 
		if(now->next==NULL && data==0){	//刪最後一個node 
			temp->next=NULL;
			free(now);
		}else if(now->next==NULL && data!=0){	//欲刪除的index已超出目前list的元素個數，直接return 
			return;
		}else if(now->next!=NULL/* && data==0*/){	//list的中間 
			temp->next=now->next;	//temp接到now的下一個 
			free(now);
		}
	}
}
