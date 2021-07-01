#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct _node{
	long long num;
	struct _node *left,*right;
}Node;

char str[5000010];
long long p,q,pos,len;

Node* buildtree();
Node* makenode(long long);
long long eval(Node*);
void preorder(Node* root)
{
	if(root!=NULL){
		printf("%d,",root->num);
		preorder(root->left);
		preorder(root->right);
	}
}

int main(void)
{
	scanf("%lld%lld",&p,&q);
	scanf("%s",str);
	pos=0,len=strlen(str);
	
	Node* root=buildtree();
	/*preorder(root);
	printf("\n");*/

	printf("%lld\n",eval(root));
	return 0;
}
Node* makenode(long long n)
{
	Node* node=(Node*)malloc(sizeof(Node));
	node->num=n;
	node->left=node->right=NULL;
	return node;
}
Node* buildtree()
{
	Node* node=NULL;
	
	while(str[pos]==')' || str[pos]==','){
		pos++;
	}
	
	if(pos<len){
		//printf("pos=%d,str[pos]=%c\n",pos,str[pos]);
		if(str[pos]=='f'){
			node=makenode(-1);
			pos+=2;
			node->left=buildtree();
			node->right=buildtree();
		}else if('0'<=str[pos] && str[pos]<='9'){
			long long n=str[pos]-'0';
			while('0'<=str[pos+1] && str[pos+1]<='9'){
				n=n*10+str[pos+1]-'0';
				pos++;
			}
			pos+=2;
			node=makenode(n);
		}
	}
	return node;
}
long long eval(Node* root)
{
	if(root->num==-1){
		return  (( (p%q)*(eval(root->left)%q) )%q+ eval(root->right)%q )%q;
	}else{
		return root->num;
	}
}
