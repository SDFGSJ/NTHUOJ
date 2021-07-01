#include<stdio.h>
#include<string.h>
#include<stdlib.h>
typedef struct _Node{
    int val;
    struct _Node* left, *right;
} Node;

int boolean[3010];
int len, pos;
char expr[20010];
char boolexp[3010];

Node* buildTree();
int judge(int, Node*);
void printTree(Node*);

int main(){
    scanf("%s",expr);
    len = strlen(expr);
    Node* root = buildTree();
    int N;
    scanf("%d",&N);
    while(N--){
        scanf("%s",boolexp);
        for(int i = 0; boolexp[i] != '\0'; i++)
            boolean[i+1] = boolexp[i]-'0';
        int ans = judge(boolean[root->val], root);
        printf("%d\n",ans);
    }
    return 0;
}

Node* buildTree(){
    if(pos >= len) return NULL;
    int v = expr[pos++]-'0';
    //printf("%c%d\n",c,v);
    while(expr[pos]<='9' && expr[pos]>='0'){
        v = v*10+(expr[pos++]-'0');
    }
    Node* root = (Node*) malloc(sizeof(Node));
    root->val = v;
    root->left = root->right = NULL;
    if(expr[pos] == '?'){
        pos++;
        root->left = buildTree();
        root->right = buildTree();
        return root;
    }else if(expr[pos] == ':'){
        pos++;
        return root;
    }else if(expr[pos] == '\0')
		return root;
    else
		return NULL;
}

int judge(int v, Node* node){
    if(node->left != NULL && node->right != NULL)
		return v ? judge(boolean[node->left->val], node->left) : judge(boolean[node->right->val], node->right);
    else
		return v;
}
