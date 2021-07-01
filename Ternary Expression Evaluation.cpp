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
		
		if('0'<=c && c<='9'){	//�p�G�O�Ʀr���ܴN�ؤ@��node����
			num=c-'0';
			while('0'<=str[now+1] && str[now+1]<='9'){
				num=num*10+str[now+1]-'0';
				now++;
			}			
			node=makenode(num),now++;
			/*�`�N���O�b�o��Nnode->left=expr()�Bnode->right=expr()�A���i��Ʀr�᭱�S���F��*/
		}
		
		if(str[now]=='?'){	//'?'�᭱�~�n��left right subtree
			now++;	//������Ʀr
			node->left=expr();
			node->right=expr();
		}else{	//':'-->��������᭱���Ʀr
			now++;
		}
	}
	return node;
}
void eval(Node* root)
{
	if(root!=NULL){
		if(val[ root->n - 1 ]=='1'){	//�p�G�o��node��True�A�n������
			if(root->left!=NULL){	//�p�G��left node�A�N��ans�]��left node����
				ans=val[root->left->n - 1]-'0';
				eval(root->left);	//�~�򩹥���
			}else{	//�p�G�S��left node�A�N��ans�]��root��������(��Ispecial case�u���@�ӼƦr���ɭ�)
				ans=val[root->n - 1]-'0';
			}
		}else{	//�p�G�o��node��False�A�n���k��
			if(root->right!=NULL){	//�p�G��right node�A�N��ans�]��right node����
				ans=val[root->right->n - 1]-'0';
				eval(root->right);	//�~�򩹥k��
			}else{	//�p�G�S��right node�A�N��ans�]��root��������(��Ispecial case�u���@�ӼƦr���ɭ�)
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
