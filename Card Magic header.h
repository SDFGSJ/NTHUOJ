#ifndef __FUNCTION_H__
#define __FUNCTION_H__
#include<stdio.h>
#include<stdlib.h>

typedef struct _Node{
    int size;
    int* data;
    struct _Node* next;
}Node;

Node* ReadOneList();
void PrintList(Node*);
void Merge(Node*,int,int);
void Cut(Node*,int,int);

Node* ReadOneList()
{
	int i;
	
	//建立一個node 
	Node* newnode=(Node*)malloc(sizeof(Node));
	
	//建立陣列 
	int array_size;
	scanf("%d:",&array_size);
	int* array=(int*)malloc(sizeof(int)*array_size);
	for(i=0;i<array_size;i++){
		scanf("%d",&array[i]);
	}
	
	//填入資訊
	newnode->data=array;
	newnode->size=array_size;
	newnode->next=NULL;	//這一步可以讓list的最後指到NULL 
	
	return newnode;
}
void PrintList(Node* head)
{
	int i;
	
	//移到第一個node
	head=head->next;
	while(head!=NULL){
		if(head->data!=NULL){
			for(i=0;i<head->size;i++){
				if(i==0){
					printf("%d",(head->data)[i]);
				}else{
					printf(" %d",(head->data)[i]);
				}
			}
			printf("\n");
		}
		head=head->next;
	}
}
void Merge(Node* dummy_head, int from, int to)	//from放在to的上面
{	
	/*dont free the node*/
	int i;
	
	//先宣告兩個從起點開始走的指標 
	Node *stack_from=dummy_head,*stack_to=dummy_head;
	
	//走到該node
	/*注意:一定要檢查走到的node有沒有data，否則會造成RE
	如果有->就算一個完整的node
	如果沒有->就不算一個完整的node，from,to要++
	因為是從dummy_head出發，所以是a--不是--a*/
	while(from--){
		stack_from=stack_from->next;
		if(stack_from->data==NULL){
			from++;
		}
	}
	while(to--){
		stack_to=stack_to->next;
		if(stack_to->data==NULL){
			to++;
		}
	}
	
	//建立一個新的array 
	int new_array_size = (stack_from->size) + (stack_to->size);	
	int* new_array=(int*)malloc(sizeof(int) * new_array_size);
	
	//先抄to再抄from
	for(i=0 ; i<(stack_to->size) ; i++){
		new_array[i]=(stack_to->data)[i];
	}
	for(i=(stack_to->size) ; i<new_array_size ; i++){
		new_array[i]=(stack_from->data)[ i-(stack_to->size) ];
	}
	
	/*printf("debug:");
	for(i=0;i<new_array_size;i++){
		printf("%d,",new_array[i]);
	}
	printf("\n");*/
	
	//丟掉from的舊陣列
	free(stack_from->data);
	stack_from->data=NULL;
	
	//丟掉to的舊陣列
	free(stack_to->data);
	
	//更新to的資訊 
	stack_to->size=new_array_size;
	stack_to->data=new_array;
}
void Cut(Node* dummy_head, int x, int i)	//cut the x-th card stack into two stacks: (1~i)、remaining 
{
	/*dont free the node*/
	int j;
	
	//宣告一個從dummy_head出發的指標 
	Node* stack_x=dummy_head;
	
	//建立一個node 
	Node* newnode=(Node*)malloc(sizeof(Node));
	
	//走到該node
	/*注意:一定要檢查走到的node有沒有data，否則會造成RE
	如果有->就算一個完整的node
	如果沒有->就不算一個完整的node，from,to要++*/
	while(x--){
		stack_x=stack_x->next;
		if(stack_x->data==NULL){
			x++;
		}
	}
	
	//需要兩個新的陣列來存放切割後的陣列 
	int* origin_ar=(int*)malloc(sizeof(int) * i);
	int* remain_ar=(int*)malloc(sizeof(int) * (stack_x->size - i));
	
	//抄數字 
	for(j=0;j<i;j++){
		origin_ar[j]=(stack_x->data)[j];
	}
	for(j=0;j<(stack_x->size)-i;j++){
		remain_ar[j]=(stack_x->data)[i+j];
	}
	
	//抄完數字之後就丟掉x的舊陣列
	free(stack_x->data);
	stack_x->data=NULL;
	
	//將newnode加到list裡面
	newnode->next=stack_x->next;
	stack_x->next=newnode;
	
	//將兩個array跟node連接起來
	stack_x->data=origin_ar;
	newnode->data=remain_ar;
	
	//更新node的資訊 
	/*注意:要先更新newnode->size，因為如果先更改stack_x->size會錯*/
	newnode->size=(stack_x->size)-i;
	stack_x->size=i;
}
#endif
