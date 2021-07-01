#include<stdio.h>
//#include<stdlib.h>
//#include<string.h>
#define MAXN 200002

int lch[MAXN],rch[MAXN];	// left child, right child
int node_index[MAXN];		// node_index[i] means node[i]'s index in the inorder sequence
int point_to[MAXN];			// point_to[i] means the # of node point to node[i]
int inorder[MAXN];			// correct inorder sequence that we gave
int ans[MAXN];				// the inorder sequence of our final tree structure
int root,idx;

//inorder
void traverse(int node){
    if(node){
        traverse(lch[node]);
        ans[idx++]=node;
        traverse(rch[node]);
    }
}

int main(){
    int n,i;

    while(scanf("%d",&n)!=EOF){
    	//initial point_to array
		for(i=1;i<=n;i++) {
            point_to[i]=0;
        }
        
        //Assuming that the first node is on the left, and the second node is on the right.
        for(i=1;i<=n;i++){
            scanf("%d%d",&lch[i],&rch[i]);
            point_to[lch[i]]+=1;
			point_to[rch[i]]+=1;
        }

        //Read in inorder sequence and record the index of inorder[i]
        for(i=1;i<=n;i++){
            scanf("%d",&inorder[i]);
            node_index[inorder[i]]=i;
        }

        //If no one point to the node that means the node is root
        for(i=1;i<=n;i++){
            if(!point_to[i]){
                root=i;
                break;
            }
        }
        
		/*printf("point_to[]=");
		for(i=0;i<=n;i++){
			printf("%d,",point_to[i]);
		}
		printf("\n");
		
		printf("node_index[]=");
		for(i=1;i<=n;i++){
			printf("%d,",node_index[i]);
		}
		printf("\n");
		
		printf("lch[]=");
		for(i=1;i<=n;i++){
			printf("%d,",lch[i]);
		}
		printf("\n");
		
		printf("rch[]=");
		for(i=1;i<=n;i++){
			printf("%d,",rch[i]);
		}
		printf("\n");*/
		
		
        // KEY: For every node,
        //      comparing the node's index in inorder sequence and the node's left child's index in inorder sequence.
        //      If left child index in the inorder sequence is greater than node's index,
        //      it means that the left child should be the right child, actually.
        //      Similarly, if the right child index in the inorder sequence is less than the node's index,
        //      it means that your right child should be your left child, actually.
        //      Note that both checking should be made since any side of child node might be missing.
        //
        //      ex:     0     Take node 0 for example.
        //             / \    If lch[0]=2 and rch[0]=1, inorder sequence = 102,
        //            1   2   we can see that node_index[lch[0]]=2 is greater than node_index[0]=1.
        //                    Meaning that the node 2 is actually the right child.
        //                    Then we need to exchange lch[0] ans rch[0] to form the correct order.
        //
        for(i=1;i<=n;i++){
            int tmp;
            if(lch[i]!=0 && node_index[lch[i]] > node_index[i]) {
                tmp=lch[i];
                lch[i]=rch[i];
                rch[i]=tmp;
            }
            if(rch[i]!=0 && node_index[rch[i]] < node_index[i]) {
                tmp=rch[i];
                rch[i]=lch[i];
                lch[i]=tmp;
            }
        }
		
		/*printf("after swap:lch[]=");
		for(i=1;i<=n;i++){
			printf("%d,",lch[i]);
		}
		printf("\n");
		
		printf("after swap:rch[]=");
		for(i=1;i<=n;i++){
			printf("%d,",rch[i]);
		}
		printf("\n");*/
		
		
        // From now on, we have built the tree according to the given input.
        // We're going to check whether the inorder sequence of this tree is as same as the input one.
        
        // Initial the idx every time,
        // and construct the inorder sequence with the left and right children after reorganizing.
        idx=1;
        traverse(root);
		
		/*printf("ans[]=");
		for(i=1;i<=n;i++){
			printf("%d,",ans[i]);
		}
		printf("\n");*/
		
        // Compare our final result with the input inorder sequence.
        for(idx=1;idx<=n;idx++){
            if(ans[idx]!=inorder[idx]){
                printf("NO\n");
                break;
            }
        }
        if(idx==n+1)
			printf("YES\n");
    }
    return 0;
}
