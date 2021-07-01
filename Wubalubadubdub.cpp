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
	
	//從root開始(因為postorder最後一個數字是root node，所以post=idx-1)
	post=idx-1;
	
	//將root node left,right subtree 的值域設為(INT_MIN,INT_MAX)
	Node* root=buildtree(INT_MIN,INT_MAX);
	
	root_id=root->data;	//記住root的數字方便以後處理output
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
	
    //如果這個元素不在值域裡就return
	int data=num[post];
	if(data<min || data>max){
		return NULL;
	}
	
	//建立root node
	Node* root=makenode(data);
	post--;
	
	/*因為postorder的列印順序是(left)(right)(root)再加上從num[]後面讀取數字，所以要先建立right subtree*/
	
    //因為在right subtree的所有元素都比root node還大，所以要更新範圍[data+1,max]
	root->right=buildtree(data+1,max);
	
    //因為在left subtree的所有元素都比root node還小，所以要更新範圍[min,data-1]
	root->left=buildtree(min,data-1);
	
	return root;
}
void preorder(Node* root)
{
	if(root!=NULL){
		if(root->data==root_id){	//處理root的io比較簡單
			printf("%d",root->data);
		}else{
			printf(" %d",root->data);
		}
		preorder(root->left);
		preorder(root->right);
	}
}
