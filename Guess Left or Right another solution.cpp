#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct _BTNode{
    int data;
    struct _BTNode *left, *right;
}BTNode;

int* preds;
BTNode* nodes;
int given[200000];
int where[200001];
BTNode* buildBT(int);
int matching(BTNode*, int, int);

int main()
{
    //freopen("13156_sampleIn.txt", "r", stdin);
    int n;
    while(scanf("%d", &n) != EOF)
    {
        BTNode* root = buildBT(n);
        int input;
        for(int i=0;i<n;i++)
        {
            scanf("%d", &input);
            given[i] = input;
            where[input] = i;
        }
        printf(matching(root, 0, n - 1) ? "YES\n" : "NO\n");
        free(preds);
        free(nodes);
    }
    return 0;
}
BTNode* buildBT(int n)
{
    nodes = (BTNode*) malloc(sizeof(BTNode)*(n+1));
    preds = (int*) malloc(sizeof(int)*(n+1));
    memset(preds, 0, sizeof(int)*(n+1));
    for(int i=1;i<=n;i++)
    {
        int l, r;
        scanf("%d%d", &l, &r);
        if(l)
        {
            nodes[i].left = nodes + l;
            preds[l] = i;
        }
        else nodes[i].left = NULL;
        if(r)
        {
            nodes[i].right = nodes + r;
            preds[r] = i;
        }
        else nodes[i].right = NULL;
        nodes[i].data = i;
    }

    int root;
    for(int i=1;i<=n;i++)
    {
        if(preds[i] == 0)
        {
            root = i;
            break;
        }
    }
    return nodes + root;
}
int matching(BTNode* root, int lower, int upper)
{
    if(root == NULL) return 1;
    if(lower > upper) return 0;
    int l_ans, r_ans;
    long long l_diff = 0, r_diff = 0;
    // Notice that the type of l_diff and r_diff must be long long, because 2*10^5 * 2*10^5 > 10^9
    if(root->left != NULL)
    {
        if(where[root->left->data] > upper || where[root->left->data] < lower) return 0;
        l_diff = where[root->left->data] - where[root->data];
    }
    if(root->right != NULL)
    {
        if(where[root->right->data] > upper || where[root->right->data] < lower) return 0;
        r_diff = where[root->right->data] - where[root->data];
    }

    if(l_diff*r_diff < 0)
    {
        if(l_diff < 0)
        {
            l_ans = matching(root->left, lower, where[root->data] - 1);
            r_ans = matching(root->right, where[root->data] + 1, upper);
            return l_ans && r_ans;
        }
        else
        {
            l_ans = matching(root->left, where[root->data] + 1, upper);
            r_ans = matching(root->right, lower, where[root->data] - 1);
            return l_ans && r_ans;
        }
    }
    else if(l_diff*r_diff == 0)
    {
        if(l_diff)
        {
            if(l_diff > 0)
            {
                if(where[root->data] != lower) return 0;
                return matching(root->left, lower + 1, upper);
            }
            else
            {
                if(where[root->data] != upper) return 0;
                return matching(root->left, lower, upper - 1);
            }
        }
        else if(r_diff)
        {
            if(r_diff > 0)
            {
                if(where[root->data] != lower) return 0;
                return matching(root->right, lower + 1, upper);
            }
            else
            {
                if(where[root->data] != upper) return 0;
                return matching(root->right, lower, upper - 1);
            }
        }
        else
        {
            return given[lower] == root->data;
        }
    }
    else return 0;
}
