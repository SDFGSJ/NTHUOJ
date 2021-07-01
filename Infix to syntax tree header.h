#ifndef FUNCTION_H
#define FUNCTION_H

#include<stdlib.h>
#define MAXEXPR 256
#define NUMSYM 6

char expr[MAXEXPR];  // string to store the input expression.
int pos;             // current position of parsing, from end to start

typedef enum {ID_A, ID_B, ID_C, ID_D, OP_AND, OP_OR} TokenSet;
char sym[NUMSYM];

typedef struct _Node{
    TokenSet data;
    struct _Node *left, *right;
}BTNode;

BTNode* EXPR();
BTNode* FACTOR();
BTNode* makeNode(char c);
void freeTree(BTNode *root);
void printPrefix(BTNode *root);

BTNode* EXPR()	//EXPR = FACTOR | EXPR OP FACTOR
{
	char c;
	BTNode *node=NULL,*right=NULL;
	if(pos>=0){
		right=FACTOR();	//right subtree接factor
		
		if(pos>0){
			c=expr[pos],pos--;
			if(c=='&' || c=='|'){
				node=makeNode(c);	//op當作parent 
				node->right=right;	//right subtree接factor
				node->left=EXPR();	//left subtree接expression
			}else{	//如果是字母就用node記住
				node=right;
			}
		}else{	//如果expr沒字了就用node記住這個factor
			node=right;
		}
	}
	return node;
}
BTNode* FACTOR()	//FACTOR = ID | (EXPR)
{
	char c;
	BTNode* node=NULL;
	if(pos>=0){
		c=expr[pos],pos--;
		if('A'<=c && c<='D'){
			node=makeNode(c);
		}else if(c==')'){
			node=EXPR();
			/*if(expr[pos--]!='('){
				printf("unmatched!\n");
			}*/
		}
	}
	return node;
}

BTNode* makeNode(char c)
{
	int i;
	BTNode* newnode=(BTNode*)malloc(sizeof(BTNode));
	for(i=0;i<NUMSYM;i++){	//將char轉成TokenSet，方便以後辨識
		if(c==sym[i]){
			newnode->data=i;
			break;
		}
	}
	newnode->left = newnode->right = NULL;
	return newnode;
}
#endif
