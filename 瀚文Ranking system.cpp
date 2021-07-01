//#define grorge
#ifndef grorge
#include <stdio.h>
#include <string.h>
#include <stdlib.h>


typedef struct{
    int score;
    char* name;
} Node;

// N = number of nodes in Table

void Insert( Node** Table, int N, int score, char* name );
void Delete( Node** Table, int N, char* name );
int* Top( Node** Table, int N, int x);

#define MAX_SIZE 1000
#define MAX_LEN 100
int N = 0;
Node* Table[MAX_SIZE];
#endif

//code
#include <bits/stdc++.h>
using namespace std;
#ifdef grorge
#include "function.h"
#endif // grorge
bool cmp(Node* a, Node* b){
//    if(a->score != b->score)
//        return a->score > b->score;
//    return a->name > b->name;
    if(a->score == b->score)
        return (strcmp(a->name,b->name)>0?0:1);
    return a->score > b->score;
}

void Insert( Node** Table, int N, int score, char* name ){
    Table[N] = (Node*)malloc(sizeof(Node));
    Table[N]->name = (char*)malloc(sizeof(char) * 100+5);
    strcpy(Table[N]->name, name);
    Table[N]->name[strlen(name)] = '\0';
    Table[N]->score = score;
    return;
}

void Delete( Node** Table, int N, char* name ){
    bool flag = 0;
    for(int i = 0 ; i < N ; i++){
        if(strcmp(name,Table[i]->name) == 0){
            swap(Table[i],Table[N-1]);
            free(Table[N-1]->name);
            free(Table[N-1]);
            Table[N-1] = NULL;
            flag = 1;
            break;
        }
    }
    if(!flag)exit(1);
    return;
}

int* Top( Node** Table, int N, int x){
    sort(Table, Table + N, cmp);
    int* re = (int*)malloc(sizeof(int) * x);
    for(int i = 0 ; i < x ; i++){
        re[i] = i;
    }
    return re;
}



//code
#ifndef grorge
int main(){
    for(int i=0; i<MAX_SIZE; i++)
        Table[i] = NULL;

    int K;
    scanf("%d", &K);

    char op[10];

    while( K-- ){
        // printf("K: %d\n", K);
        scanf("%s", op);
        if( strcmp(op, "INSERT" ) == 0 ){
            int score;
            char name[MAX_LEN+1];
            scanf("%d %s", &score, name );

            Insert(Table, N, score, name );
            N++;
        }
        else if( strcmp(op, "DELETE" ) == 0 ){
            char name[MAX_LEN+1];
            scanf("%s", name);

            Delete(Table, N, name );
            N--;
        }
        else if( strcmp(op, "TOP" ) == 0 ){
            int x;
            scanf("%d", &x);

            int* idxs = Top(Table, N, x);
            printf("Top %d:\n", x);
            for(int i=0; i<x; i++){
                printf("%d %s\n", Table[idxs[i]]->score, Table[idxs[i]]->name );
            }
            free( idxs );
        }
    }
    for(int i=0; i<MAX_SIZE; i++){
        if( Table[i] != NULL ){
            free(Table[i]->name);
            free(Table[i]);
            Table[i] = NULL;
        }
    }

    return 0;
}
#endif // grorge
