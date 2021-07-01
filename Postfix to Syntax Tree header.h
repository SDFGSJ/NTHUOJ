#include<stdlib.h>
typedef struct treeNode{
    char data;
    struct treeNode* left;
    struct treeNode* right;
}Node;

char s1[100],s2[100];
int idx;

void constructTree(Node** head);
void printInfix(Node* root);
void freeTree(Node* root);

void constructTree(Node** head)
{
	int len=strlen(s2);
	if(idx<len){
		char c=s2[idx];idx++;
		if(c=='&' || c=='|'){
			*head=(Node*)malloc(sizeof(Node));
			(*head)->data=c;
			constructTree(&(*head)->right);
			constructTree(&(*head)->left);
		}else{
			*head=(Node*)malloc(sizeof(Node));
			(*head)->data=c;
			(*head)->left = (*head)->right = NULL;
		}
	}
}
