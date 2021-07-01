#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct treeNode{
    char data;
    struct treeNode* left;
    struct treeNode* right;
}Node;

void constructTree(Node** head);
void printInfix(Node *root)
{
    if (root != NULL) {
        printInfix(root->left);

        printf("%c", root->data);

        if((root->data == '|' || root->data == '&') && (root->right->left != NULL && root->right->right != NULL))
            printf("(");

        printInfix(root->right);

        if((root->data == '|' || root->data == '&') && (root->right->left != NULL && root->right->right != NULL))
            printf(")");
    }
}
void freeTree(Node *root)
{
    if (root!=NULL)
    {
        freeTree(root->left);
        freeTree(root->right);
        free(root);
    }
}

int idx;
char s1[100],s2[100];

int main(void)
{
    int n;
    int i,j;
    scanf("%d",&n);

    while(n>0)
    {
        scanf("%s",s1);
        idx=0;
        for(i=0;i<strlen(s1);i++){	//s2是倒過來的s1
            s2[i]=s1[strlen(s1)-1-i];
        }
        //printf("s2=%s",s2);
        Node* root=NULL;
        constructTree(&root);
        printInfix(root);
        printf("\n");
        freeTree(root);
        n--;
    }

    return 0;
}
void constructTree(Node** head)
{
	int len=strlen(s2);
	if(idx<len){
		char c=s2[idx];idx++;
		if(c=='&' || c=='|'){
			(*head)=(Node*)malloc(sizeof(Node));
			(*head)->data=c;
			constructTree(&(*head)->right);	//先建right subtree
			constructTree(&(*head)->left);	//再建left subtree
		}else{
			(*head)=(Node*)malloc(sizeof(Node));
			(*head)->data=c;
			(*head)->left=(*head)->right=NULL;
		}
	}
}
