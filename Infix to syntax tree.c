#include<stdio.h>
#include<string.h>
#include<stdlib.h>

#define MAXEXPR 256
#define NUMSYM 6

char expr[MAXEXPR];  // store the input expression
int pos;             // current position of parsing, from end to start

typedef enum {ID_A, ID_B, ID_C, ID_D, OP_AND, OP_OR} TokenSet;
char sym[NUMSYM]="ABCD&|";

typedef struct _Node{
    TokenSet data;
    struct _Node *left, *right;
}BTNode;

BTNode* EXPR();
BTNode* FACTOR();
BTNode* makeNode(char c);
void freeTree(BTNode *root);
void printPrefix(BTNode *root);

int main(void){
    while( ~scanf("%s", expr) ){
        pos=strlen(expr)-1;
        BTNode *root=EXPR();
        printPrefix(root);
        printf("\n");
        freeTree(root);
    }
    return 0;
}
BTNode* EXPR()	//EXPR = FACTOR | EXPR OP FACTOR
{
	char c;
	BTNode *node=NULL,*right=NULL;
	if(pos>=0){
		right=FACTOR();
		
		if(pos>0){
			c=expr[pos],pos--;
			if(c=='&' || c=='|'){
				node=makeNode(c);
				node->right=right;
				node->left=EXPR();
			}else{
				node=right;
			}
		}else{
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
			/*printf("pos+1=%d,expr[pos+1]=%c\n",pos+1,expr[pos+1]);
			if(expr[pos+1]!='('){
				printf("unmatched!\n");
			}
			pos--;*/
		}
	}
	return node;
}

BTNode* makeNode(char c)
{
	int i;
	BTNode* newnode=(BTNode*)malloc(sizeof(BTNode));
	
	for(i=0;i<NUMSYM;i++){
		if(c==sym[i]){
			newnode->data=i;
			break;
		}
	}
	
	newnode->left = newnode->right = NULL;
	
	return newnode;
}

/*print a tree by pre-order*/
void printPrefix(BTNode *root){
    if (root != NULL) {
        printf("%c",sym[root->data]);
        printPrefix(root->left);
        printPrefix(root->right);
    }
}

/*clean a tree*/
void freeTree(BTNode *root){
    if (root!=NULL) {
        freeTree(root->left);
        freeTree(root->right);
        free(root);
    }
}
