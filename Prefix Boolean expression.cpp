#include<stdio.h>
#include<stdlib.h>
typedef struct _node{
	char ch;
	struct _node *left,*right;
}Node;

Node* buildtree(Node* root);
Node* makenode(char);
int solve(Node* root,int num);

char str[35];

int main(void)
{
	int i;
	
	//建立syntax tree
	Node* root=buildtree(root);
	
	for(i=0;i<16;i++){
		printf("%d %d %d %d %d\n",(i>>3)&1,(i>>2)&1,(i>>1)&1,i&1,solve(root,i));
	}
	return 0;
}
Node* buildtree(Node* root)
{
	char ch;
	Node* now;
	scanf("%c",&ch);	//在這邊讀取字元
	
	if(ch=='|' || ch=='&'){
		now=makenode(ch);
		now->left=buildtree(now->left);
		now->right=buildtree(now->right);
	}else{
		now=makenode(ch);
	}
	return now;
}
Node* makenode(char c)
{
	Node* newnode=(Node*)malloc(sizeof(Node));
	newnode->ch=c;
	newnode->left = newnode->right = NULL;
	return newnode;
}
int solve(Node* root,int num)
{
	if(root->ch=='&'){
		return solve(root->left,num) & solve(root->right,num);
	}else if(root->ch=='|'){
		return solve(root->left,num) | solve(root->right,num);
	}else{
		return ( num >> ( 3 - (root->ch - 'A') ) ) & 1;	//取出該字母在num二進位表示法中的位數
	}
}
