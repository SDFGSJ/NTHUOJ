#include <stdio.h>
#include <stdlib.h>

#define MAXN 200002

int ch[MAXN][2];
int node_index[MAXN];     // node_index[i] means node[i]'s index in the inorder sequence
int hit[MAXN];

int build_success(int root, int left, int right) {
    int *cs = ch[root];
    if (cs[0] != 0 && cs[1] != 0) {
        // both left or both right
        if ((node_index[cs[0]] > node_index[root]) == (node_index[cs[1]] > node_index[root]))
            return 0;
    }
    for (int i = 0; i < 2; i++) {
        int child = cs[i];
        int c_idx = node_index[child];
        if (child != 0) {
            if (c_idx < left || c_idx >= right) return 0;  // not in current tree
            if (c_idx < node_index[root]) {  // left subtree
                if (build_success(child, left, node_index[root]) == 0) return 0; 
            }
            else {  // right subtree
                if (build_success(child, node_index[root] + 1, right) == 0) return 0;
            }
        }
    }
    return 1;
}


int main(int argc, const char * argv[]) {
    int N;

    while(scanf("%d", &N) != EOF) {

        for(int i=1; i<=N; i++) {
            scanf("%d %d", &ch[i][0], &ch[i][1]);
            hit[ch[i][0]] = hit[ch[i][1]] = 1;
        }

        // Read in inorder sequence and record the index of inorder[i]
        int tmp;
        for(int i=1; i<=N; i++) {
            scanf("%d", &tmp);
            node_index[tmp] = i;
        }

        // find the root
        int root;
        for(int i=1; i<=N; i++) {
            if(!hit[i]) {
                root = i;
                break;
            }
        }
        
        if (build_success(root, 1, N+1)) 
        	printf("YES\n");
        else
        	printf("NO\n");

        // initial hit array
        for(int i=1; i<=N; i++) {
            hit[i] = 0;
        }
    }
    return 0;
}
