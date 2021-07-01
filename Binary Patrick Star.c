#include<stdio.h>
#include<stdlib.h>
#define maxN 1000000
typedef struct _Node{
	struct _Node *left,*right;
	int id;
}Node;

Node* buildBinaryTree(int,int*,int*);
void Traversal(Node*,int*);
void freeBinaryTree(Node*);

int lch[maxN],rch[maxN],sz[maxN];

int main(){
	int n;
	while(~scanf("%d", &n)){
		for(int i=0;i<n;i++){
			scanf("%d%d",lch+i,rch+i);
		}
		Node* root=buildBinaryTree(n,lch,rch);
		/*for(int i=0;i<n;i++){
			if(root[i].left!=NULL){
				printf("root[%d] left  --> root[%d]\n",i,root[i].left-root);
			}else{
				printf("root[%d] left  --> NULL\n",i);
			}
			if(root[i].right!=NULL){
				printf("root[%d] right --> root[%d]\n",i,root[i].right-root);
			}else{
				printf("root[%d] right --> NULL\n",i);
			}
		}*/
		Traversal(root,sz);
		for(int i=0;i<n;i++){
			printf("%d%c",sz[i]," \n"[i == n - 1]);
		}
		freeBinaryTree(root);
	}
}
Node* buildBinaryTree(int n,int* lch,int* rch)
{
	int i;
	Node* tree=(Node*)malloc(sizeof(Node)*n);
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
void Traversal(Node* root,int* size)	//記得加上自己本身(+1)
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
