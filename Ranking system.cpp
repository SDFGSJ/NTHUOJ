#include <stdio.h>
#include <string.h>
#include <stdlib.h>
typedef struct{
    int score;
    char* name;
}Node;
#define MAX_SIZE 1000
#define MAX_LEN 100
int N=0;
Node* Table[MAX_SIZE];
void Insert( Node** Table, int N, int score, char* name );
void Delete( Node** Table, int N, char* name );
int* Top( Node** Table, int N, int x);
int cmp(const void *a,const void *b);

int main(void){
	int i;
    for(i=0;i<MAX_SIZE;i++)
        Table[i]=NULL;

    int K;
    scanf("%d",&K);

    char op[10];

    while(K--){
        // printf("K: %d\n", K);
        scanf("%s",op);
        if( strcmp(op,"INSERT")==0 ){
            int score;
            char name[MAX_LEN+1];
            scanf("%d%s",&score,name);

            Insert(Table,N,score,name);
            N++;
        }
        else if( strcmp(op,"DELETE")==0 ){
            char name[MAX_LEN+1];
            scanf("%s",name);

            Delete(Table,N,name);
            N--;
        }
        else if( strcmp(op,"TOP")==0 ){
            int x;
            scanf("%d",&x);

            int* idxs=Top(Table,N,x);
            printf("Top %d:\n", x);
            for(i=0;i<x;i++){
                printf("%d %s\n",Table[idxs[i]]->score,Table[idxs[i]]->name);
            }
            free(idxs);	//注意這邊有free
        }
        /*
		printf("目前有%d個元素\n",N);
        for(i=0;i<N;i++){
        	printf("Table[%d]:%d %s\n",i,Table[i]->score,Table[i]->name);
		}
		for(i=0;i<N;i++){
			printf("Table[%d]位址:%p\n",i,Table[i]);
		}
		*/
    }
    for(i=0;i<MAX_SIZE;i++){
        if(Table[i]!=NULL){
            free(Table[i]->name);	//注意這邊有free
            free(Table[i]);			//注意這邊有free
            Table[i]=NULL;
        }
    }
    return 0;
}
int cmp(const void *a,const void *b)
{
	const Node** a1=(const Node**)a;
	const Node** b1=(const Node**)b;
	if((*a1)->score > (*b1)->score){
		return -1;
	}else if((*a1)->score < (*b1)->score){
		return 1;
	}else{
		return strcmp((*a1)->name,(*b1)->name);
	}
}
void Insert(Node** Table,int N,int score,char* name)
{
	int len=strlen(name);
	Table[N]=(Node*)malloc(sizeof(Node));
	
	char *str=(char*)malloc((len+10)*sizeof(char));
	strcpy(str,name);
	
	Table[N]->name=str;
	Table[N]->score=score;
}
void Delete(Node** Table,int N,char* name)
{
	int i,start;
	for(i=0;i<N;i++){
		if(strcmp(Table[i]->name,name)==0){
			free(Table[i]->name);
			free(Table[i]);
			Table[i]=NULL;
			start=i;
			break;
		}
	}
	//往前搬
	for(i=start;i<N-1;i++){
		Table[i]=Table[i+1];
	}
	Table[N-1]=NULL;
}
int* Top(Node** Table,int N,int x)
{
	int i;
	int *rec=(int*)malloc(x*sizeof(int));
	qsort(Table,N,sizeof(Node*),cmp);
	for(i=0;i<x;i++){
		rec[i]=i;
	}
	return rec;
}
