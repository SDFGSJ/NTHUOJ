#include <stdio.h>
#include <string.h>
#include <stdlib.h>
typedef struct{
    int score;
    char* name;
}Node;
#define MAX_SIZE 1000
#define MAX_LEN 100
Node* Table[MAX_SIZE];
void Insert( Node** Table, int N, int score, char* name );
void Delete( Node** Table, int N, char* name );
int* Top( Node** Table, int N, int x);
int cmp(const void *a,const void *b);
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
	//©¹«e·h
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
