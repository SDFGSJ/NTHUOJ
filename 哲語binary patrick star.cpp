#include <stdio.h>
#include <stdlib.h>
#define maxN 1000000
typedef struct _Node {
	struct _Node *left, *right;
	int id;
} Node;

Node* buildBinaryTree(int, int*, int*);
void Traversal(Node*, int*);
void freeBinaryTree(Node*); 

int lch[maxN], rch[maxN], sz[maxN];
Node* buildBinaryTree(int n,int* lch,int* rch){
    Node* node=(Node*)malloc(sizeof(Node)*n);
    for(int i=0;i<n;i++){
        (node+i)->id=i;
        if(lch[i]!=-1)
        (node+i)->left=(node+lch[i]);
        else
        (node+i)->left=NULL;
        if(rch[i]!=-1)
        (node+i)->right=(node+rch[i]);
        else
        (node+i)->right=NULL;
    }
    return node;
}
void freeBinaryTree(Node* root){
    /*if(root->left!=NULL)
    free(root->left);
    if(root->right!=NULL)
    free(root->right);*/
    free(root);
}
void Traversal(Node* root,int* ans){
    if(root!=NULL){
        Traversal(root->left,ans);
        Traversal(root->right,ans);
        if(root->left==NULL && root->right==NULL)
        	ans[root->id]=1;
        else if(root->left==NULL)
        	ans[root->id]=ans[root->right->id]+1;
        else if(root->right==NULL)
        	ans[root->id]=ans[root->left->id]+1;
        else
        	ans[root->id]=ans[root->left->id]+ans[root->right->id]+1;
    }
}
int main() {
	int n;
	while (scanf("%d", &n) != EOF) {
		for (int i = 0; i < n; i++) {
			scanf("%d %d", lch + i, rch + i);
		}
		Node* root = buildBinaryTree(n, lch, rch);
		Traversal(root, sz);
		for (int i = 0; i < n; i++) {
			printf("%d%c", sz[i], " \n"[i == n - 1]);
		}
		freeBinaryTree(root);
	}
}
