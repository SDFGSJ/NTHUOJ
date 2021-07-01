#include<stdio.h>
#include<stdlib.h>

typedef struct treeNode{
    char data;
    struct treeNode *left;
    struct treeNode *right;
}Node;

void constructTree(Node** head);
void printInfix(Node *root);
void freeTree(Node *root);

void constructTree(Node** head)
{
    char c;

    if((*head)==NULL)
    {
        (*head)=(Node*)malloc(sizeof(Node));
		c=getchar();

		(*head)->data=c;

        (*head)->left = (*head)->right = NULL;

        if((*head)->left==NULL && ((*head)->data=='&' || (*head)->data=='|'))
            constructTree( &(*head)->left);
        if((*head)->right==NULL && ((*head)->data=='&' || (*head)->data=='|'))
            constructTree( &(*head)->right);
    }
}

void freeTree(Node *root)
{
    if(root!=NULL)
    {
        freeTree(root->left);
        freeTree(root->right);
        free(root);
    }
}

int main(void)
{
    int n;
    scanf("%d",&n);// the number of test cases

    while(n>0){
        getchar();
        Node *root=NULL;
        constructTree(&root);	// construct syntax tree
        printInfix(root);
        printf("\n");
        freeTree(root);
        --n;
    }
    return 0;
}
void printInfix(Node *root)	//�u�n&,|��right child�O&,|�N�n�L�X"()"
{
	if(root!=NULL){
		
		printInfix(root->left);
		
		printf("%c",root->data);
		
		if(root->right!=NULL && (root->right->data=='&' || root->right->data=='|')){
			printf("(");
		}
		
		printInfix(root->right);
		
		if(root->right!=NULL && (root->right->data=='&' || root->right->data=='|')){
			printf(")");
		}
	}
}
