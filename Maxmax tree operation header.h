#include<stdlib.h>
struct Node{
    int id;
    struct Node *next;
};

struct Graph{
    int vertices_num;
    struct Node** adjLists;
};

struct Graph* createGraph(int);
void addEdge(struct Graph*,int,int);
int findMax(struct Graph*,int,int);
void freeGraph(struct Graph*);

struct Graph* createGraph(int n)
{
	int i;

	struct Graph* graph=(struct Graph*)malloc(sizeof(struct Graph));
	graph->vertices_num=n;
	graph->adjLists=(struct Node**)malloc(sizeof(struct Node*) * n);
	for(i=0;i<n;i++){   //�Nadjlist��l�Ʀ�NULL
		graph->adjLists[i]=NULL;
	}

	return graph;
}
void addEdge(struct Graph* g,int u,int v)
{
	//�Nnode��badjlist���e��
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

		if(now>max) //�ˬd�ۤv���S��>max
			max=now;

        if(it->id==pre)
			continue;

		if(it->id > max){
			max=it->id;
		}

		int num=findMax(g,it->id,now);  //�λ��j�h���X���I�ҳs������L�I
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