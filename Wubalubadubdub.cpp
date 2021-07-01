#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
typedef struct _node{
	int data;
	struct _node *left,*right;
}Node;

Node* makenode(int);
Node* buildtree(int,int);
void preorder(Node*);

int num[200010];
int idx,post,root_id;

int main(void)
{	
	int n;
	while(~scanf("%d",&n)){
		num[idx]=n;
		idx++;
	}
	
	//�qroot�}�l(�]��postorder�̫�@�ӼƦr�Oroot node�A�ҥHpost=idx-1)
	post=idx-1;
	
	//�Nroot node left,right subtree ���Ȱ�]��(INT_MIN,INT_MAX)
	Node* root=buildtree(INT_MIN,INT_MAX);
	
	root_id=root->data;	//�O��root���Ʀr��K�H��B�zoutput
	preorder(root);
	printf("\n");
	return 0;
}
Node* makenode(int val)
{
	Node* newnode=(Node*)malloc(sizeof(Node));
	newnode->data=val;
	newnode->left = newnode->right = NULL;
	return newnode;
}
Node* buildtree(int min,int max)
{
	//base step
	if(post<0){
		return NULL;
	}
	
    //�p�G�o�Ӥ������b�Ȱ�̴Nreturn
	int data=num[post];
	if(data<min || data>max){
		return NULL;
	}
	
	//�إ�root node
	Node* root=makenode(data);
	post--;
	
	/*�]��postorder���C�L���ǬO(left)(right)(root)�A�[�W�qnum[]�᭱Ū���Ʀr�A�ҥH�n���إ�right subtree*/
	
    //�]���bright subtree���Ҧ���������root node�٤j�A�ҥH�n��s�d��[data+1,max]
	root->right=buildtree(data+1,max);
	
    //�]���bleft subtree���Ҧ���������root node�٤p�A�ҥH�n��s�d��[min,data-1]
	root->left=buildtree(min,data-1);
	
	return root;
}
void preorder(Node* root)
{
	if(root!=NULL){
		if(root->data==root_id){	//�B�zroot��io���²��
			printf("%d",root->data);
		}else{
			printf(" %d",root->data);
		}
		preorder(root->left);
		preorder(root->right);
	}
}
