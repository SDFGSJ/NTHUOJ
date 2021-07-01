#include<stdio.h>
#include<stdlib.h>
#include<string.h>
long long int P,Q,len;
int pos=0;
char s[6000000];
typedef struct node_{
    struct node_* left;
    struct node_* right;
    long long int val;
}Node;
Node* make_node(int a);
Node* expr(){
    Node* n=NULL;
    while(s[pos]==',' || s[pos]==')'){
        pos++;
    }
    if(pos<len){
        if(s[pos]=='f'){
            n=make_node(0);
            pos+=2;
            n->left=expr();
            n->right=expr();
            return n;
        }
        else if(s[pos]>='0' && s[pos]<='9'){
            int count;
            count=s[pos]-'0';
            while(s[pos+1]>='0' && s[pos+1]<='9'){
                count*=10;
                count+=(s[pos+1]-'0');
                pos++;
            }
            pos+=2;
            n=make_node(count);
            return n;
        }
    }
    return n;
}
Node* make_node(int a){
    Node* n=(Node*)malloc(sizeof(Node));
    n->left=NULL;
    n->right=NULL;
    n->val=a;
    return n;
}
void inorder(Node* root)
{
	if(root!=NULL){
		inorder(root->left);
		printf("%lld ,",root->val);
		inorder(root->right);
	}
}
int tr(Node* root){
    if(root->val==0){
        return ((tr(root->left)*P%Q)+ tr(root->right))%Q;
    }
    else{
        return root->val;
    }
}
int main(){
    scanf("%lld %lld",&P,&Q);
    if(P>Q)
    P=P%Q;
    scanf("%s",s);
    len=strlen(s);
    Node* root=expr();
    long long int ans;
    ans=tr(root);
    printf("%lld\n",ans);
    printf("%d",pos);
    //inorder(root);
}
