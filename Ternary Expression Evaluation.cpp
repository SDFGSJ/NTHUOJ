#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct _node{
	int n;
	struct _node *left,*right;
}Node;

char str[100010];
char val[3010];
int now,len,ans;

Node* expr();
Node* makenode(int);
void eval(Node*);
void preorder(Node*);
void inorder(Node*);
void postorder(Node*);

int main(void){
	int i;
	
	scanf("%s",str);
	len=strlen(str);
	
	Node* root=expr();
	
	int t;
	scanf("%d",&t);
	while(t--){
		scanf("%s",val);
		eval(root);
		printf("%d\n",ans);
	}
	
	/*printf("preorder=");
	preorder(root);
	printf("\n");
	printf("inorder=");
	inorder(root);
	printf("\n");
	printf("postorder=");
	postorder(root);
	printf("\n");*/
	return 0;
}
Node* makenode(int id)
{
	Node* newnode=(Node*)malloc(sizeof(Node));
	newnode->n=id;
	newnode->left = newnode->right = NULL;
	return newnode;
}
Node* expr()	//expr = val || val?expr:expr
{
	Node *node=NULL;
	if(now<len){
		char c=str[now];
		int num;
		
		if('0'<=c && c<='9'){	//如果是數字的話就建一個node給它
			num=c-'0';
			while('0'<=str[now+1] && str[now+1]<='9'){
				num=num*10+str[now+1]-'0';
				now++;
			}			
			node=makenode(num),now++;
			/*注意不是在這邊就node->left=expr()、node->right=expr()，有可能數字後面沒有東西*/
		}
		
		if(str[now]=='?'){	//'?'後面才要建left right subtree
			now++;	//先移到數字
			node->left=expr();
			node->right=expr();
		}else{	//':'-->直接移到後面的數字
			now++;
		}
	}
	return node;
}
void eval(Node* root)
{
	if(root!=NULL){
		if(val[ root->n - 1 ]=='1'){	//如果這個node為True，要往左走
			if(root->left!=NULL){	//如果有left node，就把ans設為left node的值
				ans=val[root->left->n - 1]-'0';
				eval(root->left);	//繼續往左走
			}else{	//如果沒有left node，就把ans設為root本身的值(對付special case只有一個數字的時候)
				ans=val[root->n - 1]-'0';
			}
		}else{	//如果這個node為False，要往右走
			if(root->right!=NULL){	//如果有right node，就把ans設為right node的值
				ans=val[root->right->n - 1]-'0';
				eval(root->right);	//繼續往右走
			}else{	//如果沒有right node，就把ans設為root本身的值(對付special case只有一個數字的時候)
				ans=val[root->n - 1]-'0';
			}
		}
	}
}
void preorder(Node* root)
{
	if(root!=NULL){
		printf("%d,",root->n);
		preorder(root->left);
		preorder(root->right);
	}
}
void inorder(Node* root)
{
	if(root!=NULL){
		inorder(root->left);
		printf("%d,",root->n);
		inorder(root->right);
	}
}
void postorder(Node* root)
{
	if(root!=NULL){
		postorder(root->left);
		postorder(root->right);
		printf("%d,",root->n);
	}
}
