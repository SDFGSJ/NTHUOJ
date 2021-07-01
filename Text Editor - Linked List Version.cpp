#include<stdio.h>
#include<stdlib.h>
typedef struct node{
	char c;
	struct node *next,*prev;
}Node;

char str[1000010];
Node *now,*head,*rear;

void backspace();
void makenode(char);

int main(void)
{
	int t,i;
	//����dummy head,rear 
	head=(Node*)malloc(sizeof(Node));
	rear=(Node*)malloc(sizeof(Node));
	scanf("%d",&t);
	while(t--){
		//�s��head��rear node�ê�l��now 
		head->next=rear;
		rear->prev=head;
		now=head;
		
		int len;
		scanf("%d",&len);
		scanf("%s",str);
		for(i=0;i<len;i++){
			if(str[i]=='L'){
				if(now!=head){	//��head�N����A�������F
					now=now->prev;
				}
			}else if(str[i]=='R'){
				if(now->next!=rear){	//���n���ʨ�rear node�W���A�o�˶�r�|�����D
					now=now->next;
				}
			}else if(str[i]=='B'){
				backspace();
			}else{
				makenode(str[i]);
			}
		}
		
		//��now����head���᪺�Ĥ@��node�ǳƶ}�lprint 
		now=head->next;
		while(now!=rear){
			Node* tmp=now;
			printf("%c",now->c);
			now=now->next;	//now�������U�@��node 
			free(tmp);	//�A��L�L��node free�� 
		}
		printf("\n");
	}
	free(head);
	free(rear);
	return 0;
}
void backspace()
{
	Node* tmp=now;
	if(now==head){	//�bhead node�W����backspace�A�N����return 
		return;
	}else{
		now->next->prev=now->prev;
		now->prev->next=now->next;
		now=now->prev;	//now�n����e�@��node����m 
		free(tmp);	//�A��n�R���rfree�� 
	}
}
void makenode(char ch)	//��@��node�bnow���᭱ 
{
	Node* newnode=(Node*)malloc(sizeof(Node));
	
	//���� 
	newnode->c=ch;
	
	//������ 
	newnode->next=now->next;
	newnode->prev=now;
	now->next->prev=newnode;
	now->next=newnode;
	
	//now�n����᭱�@��node(newnode)����m
	now=newnode;
}
