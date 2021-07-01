#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct _node{
	char ch;
	struct _node *left,*right;
}Node;

Node* makenode(char c);
Node* expr();
Node* factor();
void inorder(Node*);
void freetree(Node*);

char str[256];
int idx;

int main(void)
{
	Node* root;
	scanf("%s",str);
	idx=strlen(str)-1;	//記得從後面parse回來
	root=expr();
	inorder(root);
	freetree(root);
	return 0;
}
Node* makenode(char c)
{
	Node* newnode=(Node*)malloc(sizeof(Node));
	newnode->ch=c;
	newnode->left = newnode->right = NULL;
	return newnode;
}
Node* expr()	//EXPR = FACTOR | EXPR OP FACTOR
{
	char c;
	Node *right=NULL,*node=NULL;
	if(idx>=0){
		right=factor();
		
		if(idx>0){
			c=str[idx],idx--;
			if(c=='|' || c=='&'){
				node=makenode(c);
				node->right=right;
				node->left=expr();
			}else{
				node=right;
			}
		}else{
			node=right;
		}
	}
	return node;
}
Node* factor()	//FACTOR = ID | (EXPR)
{
	char c;
	Node* node=NULL;
	if(idx>=0){
		c=str[idx],idx--;
		if('A'<=c && c<='D'){
			node=makenode(c);
		}else if(c==')'){
			node=expr();
		}
	}
	return node;
}
void inorder(Node* root)
{
	if(root!=NULL){
		inorder(root->left);
		
		printf("%c",root->ch);
		
		if(root->right!=NULL && (root->right->ch=='&' || root->right->ch=='|')){
			printf("(");
		}
		
		inorder(root->right);
		
		if(root->right!=NULL && (root->right->ch=='&' || root->right->ch=='|')){
			printf(")");
		}
	}
}
void freetree(Node* root)
{
	if(root!=NULL){
		freetree(root->left);
		freetree(root->right);
		free(root);
	}
}
