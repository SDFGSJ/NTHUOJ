#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct _Node{
    int id;
    bool isleaf;
    struct _Node *left, *right, *parent;
}Node;

int inFix[200005];
int N;
Node* nodes;

int Traversal(int now, int lb, int rb){
    //lb = left bound, rb = right bound

    //printf("in %d\n",node->left->id);
    //printf("now: %d, nowPos: %d, lb: %d, rb: %d\n", now, inFix[now], lb, rb);
    //now == 0: NULL
    //isleaf: need to check the position
    if(now == 0 || (nodes[now].isleaf && inFix[now] < rb && inFix[now] > lb))
        return 1;
    int ans1, ans2;

    if(inFix[now] < rb && inFix[now] > lb){
        //if left exist, lid = leftid
        //if right exist, rid = rightid
        int lid = nodes[now].left ? nodes[now].left->id : 0;
        int rid = nodes[now].right ? nodes[now].right->id : 0;
        //ans1 = original, ans2 = rotated
        //&: both right
        ans1 = Traversal(lid, lb, inFix[now]) & Traversal(rid, inFix[now], rb);
        ans2 = Traversal(rid, lb, inFix[now]) & Traversal(lid, inFix[now], rb);
        //printf("ans1 = %d, ans2 = %d\n", ans1, ans2);
        //only one side is right
        //so if 1, 1 -> wrong
        return ans1 ^ ans2;
    }
    //printf("Fail\n");
    return 0;
}

int main(){

    while(~scanf("%d",&N)){
        nodes = (Node*) malloc((N+1) * sizeof(Node));
        
        //initailize
        for(int i = 1; i <= N; i++)
            nodes[i].parent = NULL;

        int l, r;
        for(int i = 1; i <= N; i++){
            scanf("%d%d",&l,&r);
            nodes[i].id = i;
            //nodes[i].parent = NULL;
            nodes[i].left = nodes[i].right = NULL;
            if(l == r && l == 0){
                //leaf
                nodes[i].isleaf = true;
                nodes[i].left = nodes[i].right = NULL;
            }else{
                //set left and right no matter it's right or not

                //printf("%d %d\n",l,r);
                nodes[i].isleaf = false;
                if(l != 0){
                    nodes[i].left = &nodes[l];
                    nodes[l].parent = &nodes[i];
                    //printf("%d p %d\n",l,nodes[l].parent->id);
                }
                if(r != 0){
                    nodes[i].right = &nodes[r];
                    nodes[r].parent = &nodes[i];
                    //printf("%d p %d\n",r,nodes[r].parent->id);
                }
            }
        }
        
        inFix[0] = -1;
        //set inFix
        //inFix keep the position in string of node
        for(int i = 1; i <= N; i++){
            int temp;
            scanf("%d",&temp);
            inFix[temp] = i;
        }
        
		//find root(no parent)
        int root = 0;
        for(int i = 1; i <= N; i++){
            if(nodes[i].parent == NULL){
                root = i;
                break;
            }
        }
        //printf("%d ",root);
        
		int ans = Traversal(root, 0, N+1);
        printf(ans? "YES\n" : "NO\n");
        free(nodes);
    }
    return 0;
}
