#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
typedef struct _node{
	int n;
	struct _node *up,*down,*left,*right;
}Node;

Node* makenode(int);
Node* buildtree(Node*,int,int);
void traverse(Node*);

int a[1000010];
int r,c,now,min=INT_MAX,meetdead;
Node* root;

int main(){
	int i,j;
	int row,col;
	
	scanf("%d%d",&r,&c);
	scanf("%d%d",&col,&row);
	
	for(i=0;i<r*c;i++){
		scanf("%d",&a[i]);
	}
	
	root=buildtree(root,row,col);
	traverse(root);

	printf("%d\n",min);
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
void traverse(Node* root){
	if(root==NULL){
		return;
	}
	if(root->n==-1){
		//printf("meetdead invoked!\n");
		meetdead=1;
	}
	
	
	now+=root->n;
	//printf("now=%d\n",now);
	
	traverse(root->up);
	//printf("after up:now=%d\n",now);
	
	traverse(root->right);
	//printf("after right:now=%d\n",now);
	
	traverse(root->down);
	//printf("after down:now=%d\n",now);
	
	traverse(root->left);
	//printf("after left:now=%d\n",now);
	

	if(root->up==NULL && root->right==NULL && root->down==NULL && root->left==NULL){
		//printf("meetdead=%d\n",meetdead);
		if(now<min && !meetdead){
			min=now;
			//printf("changed now=%d,min=%d\n",now,min);
		}
		meetdead=0;
	}
	now-=root->n;
}
