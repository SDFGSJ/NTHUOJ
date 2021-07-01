#include<stdio.h>
#include<stdlib.h>
typedef struct _node{
	char op;
	int num;
	struct _node *left,*right;
}Node;

Node* makenode(char);
Node* buildtree();
Node* leftspin(Node*);
Node* rightspin(Node*);
void freetree(Node*);
void calc(Node*);
void inorder(Node* root){
	if(root!=NULL){
		inorder(root->left);
		printf("%c",root->op);
		inorder(root->right);
	}
}

char str[300010];
int idx,len;

int main(void){
	scanf("%d",&len);
	scanf("%s",str);
	
	Node* first_tree=NULL;
	first_tree=buildtree();
	idx=0;
	Node* second_tree=buildtree();
	
	int ans=first_tree->num;
	while(first_tree->right->op=='+' || first_tree->right->op=='-' || first_tree->right->op=='*'){
		first_tree=leftspin(first_tree);
		calc(first_tree->left);
		calc(first_tree);
		if(first_tree->num < ans){
			ans = first_tree->num;
		}
	}
	while(second_tree->left->op=='+' || second_tree->left->op=='-' || second_tree->left->op=='*'){
		second_tree=rightspin(second_tree);
		calc(second_tree->right);
		calc(second_tree);
		if(second_tree->num < ans){
			ans = second_tree->num;
		}
	}
	printf("%d\n",ans);
	return 0;
}
Node* makenode(char ch){
	Node* node=(Node*)malloc(sizeof(Node));
	node->op=ch;
	node->num=0;
	node->left = node->right = NULL;
	return node;
}
Node* buildtree(){
	Node* root=NULL;
	if(idx<len){
		char ch=str[idx++];
		if(ch=='+' || ch=='-' || ch=='*'){
			root=makenode(ch);
			root->left=buildtree();
			root->right=buildtree();
			if(ch=='+')
				root->num = root->left->num + root->right->num;
			else if(ch=='-')
				root->num = root->left->num - root->right->num;
			else
				root->num = root->left->num * root->right->num;
		}else{
			root=makenode(ch);
			root->num=ch-'0';
		}
	}
	return root;
}
Node* leftspin(Node* root){
	Node* newroot=root->right;
	root->right=newroot->left;
	newroot->left=root;
	return newroot;
}
Node* rightspin(Node* root){
	Node* newroot=root->left;
	root->left=newroot->right;
	newroot->right=root;
	return newroot;
}
void freetree(Node* root){
	if(root!=NULL){
		freetree(root->left);
		freetree(root->right);
		free(root);
	}
}
void calc(Node* root){
	if(root->op=='+'){
		root->num = root->left->num + root->right->num;
	}else if(root->op=='-'){
		root->num = root->left->num - root->right->num;
	}else if(root->op=='*'){
		root->num = root->left->num * root->right->num;
	}
}
