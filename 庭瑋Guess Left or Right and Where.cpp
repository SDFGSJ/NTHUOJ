#include<stdio.h>
#include<stdlib.h>

typedef struct _{
    int val;
    struct _ *left, *right, *parent;
}Node;

int ip[5010];
int idx[5010];
int missingnode[10];
int missingidx[10];
int used[5010];
Node* nodes = NULL;

int N, root;
int miss1 = 0, miss2 = 0;
int ans = 0;

int checkTree(int now, int lb, int rb){
    if(now == 0 || (nodes[now].left == NULL && nodes[now].right == NULL && idx[now] < rb && idx[now] > lb)){
        return 1;
    }
    int ans1, ans2;
    if(idx[now] < rb && idx[now] > lb){
        int valL, valR;
        valL = nodes[now].left ? nodes[now].left->val : 0;
        valR = nodes[now].right ? nodes[now].right->val : 0;

        ans1 = checkTree(valL, lb, idx[now]) & checkTree(valR, idx[now], rb);
        ans2 = checkTree(valR, lb, idx[now]) & checkTree(valL, idx[now], rb);

        //printf("%d %d %d %d %d\n", now, valL, valR, ans1, ans2);
        return ans1 ^ ans2;
    }
    return 0;
}

void fillIndex(void){
    if(ans == 1)
        return;
    for(int i = 0; i < miss1; i++){
        if(ans == 1)
            return;
        if(used[missingnode[i]] == 0){
            idx[missingnode[i]] = missingidx[--miss2];
            used[missingnode[i]] = 1;
            //printf("i: %d, miss2: %d, idx: %d, node: %d\n", i, miss2, missingidx[miss2], missingnode[i]);
            if(miss2 > 0)
                fillIndex();
            else
                ans |= checkTree(root, 0, N+1);

            idx[missingnode[i]] = -1;
            used[missingnode[i]] = 0;
            miss2++;
        }
    }
}

void printInorder(int iii){
    if(nodes[iii].left != NULL) printInorder(nodes[iii].left->val);
    printf("%d ",nodes[iii].val);
    if(nodes[iii].right != NULL) printInorder(nodes[iii].right->val);
}

int main(void){

    root = miss1 = miss2 = ans = 0;
    while(~scanf("%d",&N)){

        root = miss1 = miss2 = ans = 0;
        //missed init
        for(int i = 0; i < 10; i++){
            missingidx[i] = 0;
            missingnode[i] = 0;
        }
        //used init
        for(int i = 0; i < 5010; i++)
            used[i] = 0;

        //Tree init
        nodes = (Node*) malloc((N+1) * sizeof(Node));
        for(int i = 0; i <= N; i++){
            nodes[i].left = nodes[i].right = nodes[i].parent = NULL;
            nodes[i].val = i;
        }

        //Tree input
        for(int i = 1; i <= N; i++){
            scanf("%d",&ip[i]);
            if(ip[i] == 0){
                root = i;
            }else{

                nodes[i].parent = &nodes[ip[i]];
                if(nodes[ip[i]].left == NULL)
                    nodes[ip[i]].left = &nodes[i];
                else
                    nodes[ip[i]].right = &nodes[i];
            }
        }

        //input idx
        int temp;

        for(int i = 1; i <= N; i++){
            scanf("%d",&temp);
            if(temp != 0){
                used[temp] = 1;
                idx[temp] = i;
            }
            else{
                idx[temp] = -1;
                missingidx[miss1++] = i;
            }
        }

        //find unused
        for(int i = 1; i <= N; i++){
            if(used[i] == 0){
                missingnode[miss2++] = i;
                if(miss2 >= miss1)
                    break;
            }
        }
        //find ans

        if(miss1 <= 0)
            ans |= checkTree(root, 0, N+1);
        else
            fillIndex();

        printf(ans? "YES\n" : "NO\n");
    }
    return 0;
}
