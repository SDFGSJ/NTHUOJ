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
	//產生dummy head,rear 
	head=(Node*)malloc(sizeof(Node));
	rear=(Node*)malloc(sizeof(Node));
	scanf("%d",&t);
	while(t--){
		//連接head跟rear node並初始化now 
		head->next=rear;
		rear->prev=head;
		now=head;
		
		int len;
		scanf("%d",&len);
		scanf("%s",str);
		for(i=0;i<len;i++){
			if(str[i]=='L'){
				if(now!=head){	//到head就不能再往左移了
					now=now->prev;
				}
			}else if(str[i]=='R'){
				if(now->next!=rear){	//不要移動到rear node上面，這樣塞字會有問題
					now=now->next;
				}
			}else if(str[i]=='B'){
				backspace();
			}else{
				makenode(str[i]);
			}
		}
		
		//把now移到head之後的第一個node準備開始print 
		now=head->next;
		while(now!=rear){
			Node* tmp=now;
			printf("%c",now->c);
			now=now->next;	//now先移往下一個node 
			free(tmp);	//再把印過的node free掉 
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
	if(now==head){	//在head node上不能backspace，就直接return 
		return;
	}else{
		now->next->prev=now->prev;
		now->prev->next=now->next;
		now=now->prev;	//now要指到前一個node的位置 
		free(tmp);	//再把要刪的字free掉 
	}
}
void makenode(char ch)	//塞一個node在now的後面 
{
	Node* newnode=(Node*)malloc(sizeof(Node));
	
	//填資料 
	newnode->c=ch;
	
	//接指標 
	newnode->next=now->next;
	newnode->prev=now;
	now->next->prev=newnode;
	now->next=newnode;
	
	//now要移到後面一個node(newnode)的位置
	now=newnode;
}
