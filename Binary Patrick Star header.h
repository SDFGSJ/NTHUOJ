#include<stdlib.h>
typedef struct _Node{
	struct _Node *left,*right;
	int id;
}Node;

Node* buildBinaryTree(int,int*,int*);
void Traversal(Node*,int*);
void freeBinaryTree(Node*);

Node* buildBinaryTree(int n,int* lch,int* rch)
{
	int i;
	Node* tree=(Node*)malloc(n*sizeof(Node));
	for(i=0;i<n;i++){
		tree[i].id=i;
		if(lch[i]!=-1){
			tree[i].left=tree+lch[i] ;
		}else{
			tree[i].left=NULL;
		}
		if(rch[i]!=-1){
			tree[i].right=tree+rch[i] ;
		}else{
			tree[i].right=NULL;
		}
	}
	return tree;
}
void Traversal(Node* root,int* size)	//記得加上自己(+1)
{
	if(root!=NULL){
		Traversal(root->left,size);
		Traversal(root->right,size);
		if(root->left==NULL && root->right==NULL){	//leaf node
			size[root->id]=1;
		}else if(root->left==NULL){
			size[root->id]=size[root->right->id]+1;
		}else if(root->right==NULL){
			size[root->id]=size[root->left->id]+1;
		}else{
			size[root->id]=size[root->left->id]+size[root->right->id]+1;
		}
	}
}
void freeBinaryTree(Node* root)
{
	free(root);
}
