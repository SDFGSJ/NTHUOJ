#include<stdio.h>
#include<stdlib.h>
struct Node{
    int id;
    struct Node* next;
};

struct Graph{
    int vertices_num;
    struct Node** adjLists;
};

struct Graph* createGraph(int);
void addEdge(struct Graph*,int,int);
int findMax(struct Graph*,int,int);
void freeGraph(struct Graph*);

int main(){
	int i,j;
	int n; 
	while(~scanf("%d", &n)){
		struct Graph* g=createGraph(n);
		for(i=0;i<n-1;i++){
			int u,v;
			scanf("%d%d",&u,&v);
			addEdge(g,u,v);
		}
		
		/*for(i=0;i<n;i++){
			printf("[%d]:",i);
			if(g->adjLists!=NULL){
				struct Node* t=g->adjLists[i];
				while(t!=NULL){
					printf("%d-->",t->id);
					t=t->next;
				}
			}
			printf("NULL\n");
		}*/
		
		int q;
		scanf("%d",&q);
		while(q--){
			int a,b;
			scanf("%d%d",&a,&b);
			printf("%d %d\n",findMax(g,a,b),findMax(g,b,a));
		}
		freeGraph(g);
	}
	return 0;
}
struct Graph* createGraph(int n)
{
	int i;
	
	struct Graph* graph=(struct Graph*)malloc(sizeof(struct Graph));
	graph->vertices_num=n;
	graph->adjLists=(struct Node**)malloc(sizeof(struct Node*) * n);
	for(i=0;i<n;i++){   //將adjlist初始化成NULL
		graph->adjLists[i]=NULL;
	}
	
	return graph;
}
void addEdge(struct Graph* g,int u,int v)
{
	//永遠將node塞在adjlist的前面
	struct Node* node_u=(struct Node*)malloc(sizeof(struct Node));
	node_u->id=u;
	node_u->next=g->adjLists[v];
	g->adjLists[v]=node_u;
	
	struct Node* node_v=(struct Node*)malloc(sizeof(struct Node));
	node_v->id=v;
	node_v->next=g->adjLists[u];
	g->adjLists[u]=node_v;
}
int findMax(struct Graph* g,int now,int pre)
{
	struct Node* it;
	int max=0;
	
	//printf("now=%d,pre=%d\n",now,pre);
	for(it=g->adjLists[now];it;it=it->next){
		//printf("it->id=%d\n",it->id);
		
		if(now>max) //檢查自己有沒有>max
			max=now;
			
        if(it->id==pre)
			continue;
			
		if(it->id > max){
			max=it->id;
		}
		
		int num=findMax(g,it->id,now);  //用遞迴去走訪該點所連接的其他點
		if(num>max){
			max=num;
		}
    }
    return max;
}
void freeGraph(struct Graph* g)
{
	int i;
	struct Node *now,*tmp;
	for(i=0;i<g->vertices_num;i++){
		if(g->adjLists[i]!=NULL){
			now=g->adjLists[i];
			tmp=now;
			while(now!=NULL){
				now=now->next;
				free(tmp);
				tmp=now;
			}
		}
	}
	free(g->adjLists);
	free(g);
}
