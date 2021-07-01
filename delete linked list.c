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
			now->data=num;	//��J��� 
			if(temp!=NULL){	//�p�G���O�Ĥ@��node 
				temp->next=now;	//�N�᭱��node���_�� 
				temp=now;	//temp����now
			}else{
				temp=now;
				head=now;
			}
		}else{
			now->next=NULL;	//�p�GŪ��-1�N�n��list������ 
			break;
		}
	}
	return head;
}
void deleteNode(Node ** nd, int data)
{
	Node *temp=*nd;	//temp,now���O��list���}�Y��m 
	Node *now=*nd;
	//�R���}�Y��node�n�t�~�B�z 
	if(data==1 && (*nd)!=NULL){	//�p�G�O�R���}�Y��node 
		(*nd)=(*nd)->next;	//�`�N�ʪ��Ond�A���Onow 
		free(temp);
	}else{
		while(--data && now->next!=NULL)	//�`�N�Odata-- 
		{
			temp=now;
			now=now->next;
		}
		//�`�N���Xwhile������ 
		if(now->next==NULL && data==0){	//�R�̫�@��node 
			temp->next=NULL;
			free(now);
		}else if(now->next==NULL && data!=0){	//���R����index�w�W�X�ثelist�������ӼơA����return 
			return;
		}else if(now->next!=NULL/* && data==0*/){	//list������ 
			temp->next=now->next;	//temp����now���U�@�� 
			free(now);
		}
	}
}
