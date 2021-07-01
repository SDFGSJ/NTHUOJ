#include<stdio.h>
#include<limits.h>
typedef struct _node{
	int id,mark;
	struct _node *left,*right,*parent;
}Node;

Node tree[100010];

int Min(int a,int b){
	if(a>b)	return b;
	else	return a;
}
void preorder(Node* root){
	if(root!=NULL){
		printf("%d,",root->id);
		preorder(root->left);
		preorder(root->right);
	}
}
void traversal(Node*,int,int);

int main(void)
{
	int i,j;
	int n,num;
	char ch;
	
	scanf("%d",&n);
	for(i=1;i<=n;i++){
		scanf("%d",&tree[i].id);
		tree[i].mark=0;
	}
	
	/*for(i=1;i<=n;i++){
		printf("%d,",tree[i].id);
	}
	printf("\n");*/
	
	Node* root=NULL;
	for(i=1;i<=n;i++){
		scanf("%d",&num);
		if(num!=0){
			scanf("%c",&ch);
			if(ch=='L'){
				tree[num].left=tree+i;
			}else{
				tree[num].right=tree+i;
			}
			tree[i].parent=tree+num;
		}else{
			root=tree+i;
			tree[i].parent=NULL;    //�Nroot��parent�]��NULL
		}
	}

	/*printf("preorder=");
	preorder(root);
	printf("\n");*/
	
	traversal(root,INT_MIN,INT_MAX);
	
	for(i=1;i<=n;i++){
		if(i==1){
			if(tree[i].mark<0){
				printf("%d",tree[i].mark);
			}else{
				printf("%d",tree[i].id);
			}
		}else{
			if(tree[i].mark<0){
				printf(" %d",tree[i].mark);
			}else{
				printf(" %d",tree[i].id);
			}
		}
	}
	printf("\n");
	
	return 0;
}
void traversal(Node* root,int min,int max)
{
	if(root!=NULL){
		//�p�G�Ʀr�W�� || ����parent��mark < 0 --> �N��node��mark�]��-1
		if( root->id < min || root->id > max || (root->parent!=NULL && root->parent->mark < 0) ){
			root->mark=-1;
		}
		
		//printf("root->id=%d,root->mark=%d,range=(%d,%d)\n",root->id,root->mark,min,max);
		
		traversal(root->left ,min		,root->id);
		traversal(root->right,root->id	,max);

		//�p�G����left,right child && ���̪�mark < 0 --> root mark = ����p�����@��-1
		if((root->left!=NULL && root->left->mark < 0) && (root->right!=NULL && root->right->mark < 0) && root->mark < 0){
			root->mark = Min(root->left->mark,root->right->mark)-1;
		}else if(root->left!=NULL && root->left->mark < 0 && root->mark < 0){   //�u��left child
			root->mark = root->left->mark - 1;;
		}else if(root->right!=NULL && root->right->mark < 0 && root->mark < 0){ //�u��right child
			root->mark = root->right->mark - 1;
		}
	}
}
/*
���eWA������
7
3 5 2 1 4 7 6
0 1L 1R 3L 3R 5L 5R
*/
