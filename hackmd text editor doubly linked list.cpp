#include<stdio.h>
#include<string.h>
#include<stdlib.h>

char input[1314];
int len;
typedef struct node{
    char c;
    struct node *l, *r;
}Node;                                          
void *add(Node *a, char c){                 	 //把b插入a與a後面的之間 
    Node *b = (Node*)malloc(sizeof(Node));
    b->l = NULL, b->r = NULL, b->c = c;
    if(a->r!=NULL) b->r = a->r, a->r->l = b;     //將a後面的與b的接起 
    b->l = a, a->r = b;		          //將a與b接起 
}
void erase(Node *a){ 
    a->l->r = a->r;                      
    if(a->r!=NULL) a->r->l = a->l; 
}
int main(void){
	int i;
    Node *head = (Node*)malloc(sizeof(Node));    //head 為開頭 
    head->r = NULL;
	head->l = head;
    Node *cursor = head;                         //cursor 為游標位置
    fgets(input,1314,stdin);
	len = strlen(input);
    for(i=0;i<len;i++){
        if(input[i]=='/'){                                 
            if(input[i+1]=='b') 
				erase(cursor), cursor = cursor->l, i+=9;
            else if(input[i+1]=='n') 
				add(cursor,'\n'), cursor = cursor->r, i+=7;
            else if(input[i+1]=='l'){ 
				if(cursor->l!=NULL)
					cursor = cursor->l;
				i+=4;
			}
            else if(input[i+1]=='r'){ 
				if(cursor->r!=NULL) 
					cursor = cursor->r; 
				i+=5; 
			}
        }
        else{
        	add(cursor,input[i]);
			cursor = cursor->r;
		}
    }
    head = head->r;
    while(head!=NULL)
	{
		printf("%c",head->c);
		head = head->r;
	}
    return 0;
}
