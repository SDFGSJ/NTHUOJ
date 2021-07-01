#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
typedef struct _node{
	int n;
	struct _node *up,*down,*left,*right;
}Node;

Node* makenode(int);
Node* buildtree(Node*,int,int);
void traverse(Node*,int,int);

int a[10000010];
int r,c,now,min=INT_MAX;
Node* root;

int main(){
	int i,j;
	
	scanf("%d%d",&r,&c);
	
	for(i=0;i<r*c;i++){
		scanf("%d",&a[i]);
	}
	
	root=buildtree(root,0,0);
	traverse(root,0,0);

	if(min==INT_MAX){
		printf("0\n");
	}else{
		printf("%d\n",min);
	}
	return 0;
}
Node* makenode(int num){
	Node* node=(Node*)malloc(sizeof(Node));
	node->n=num;
	node->up = node->right = node->down = node->left = NULL;
	return node;
}
Node* buildtree(Node* root,int row,int col){
	int idx=row*c+col;
	if(row<0 || r<=row || col<0 || c<=col || a[idx]==0){
		return NULL;
	}
	
	root=makenode(a[idx]);
	a[idx]=0;	//建完node以後就把這個點當作死路避免重複走訪
	
	root->up	= buildtree(root->up	,row-1	,col);
	root->right	= buildtree(root->right	,row	,col+1);
	root->down	= buildtree(root->down	,row+1	,col);
	root->left	= buildtree(root->left	,row	,col-1);
	return root;
}
void traverse(Node* root,int row,int col){
	if(root==NULL){
		return;
	}
	now+=root->n;
	
	int idx=row*c+col;
	if(idx==r*c-1){	//到destination
		if(now<min){
			min=now;
		}
	}
	
	//printf("(%d,%d):now=%d\n",row,col,now);
	traverse(root->up,row-1,col);
	//printf("after up:now=%d\n",now);

	traverse(root->right,row,col+1);
	//printf("after right:now=%d\n",now);

	traverse(root->down,row+1,col);
	//printf("after down:now=%d\n",now);

	traverse(root->left,row,col-1);
	//printf("after left:now=%d\n",now);

	now-=root->n;
}
