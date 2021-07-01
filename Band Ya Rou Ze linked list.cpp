#include<stdio.h>
#include<stdlib.h>
typedef struct _node{
	char* str;
	struct _node* next;
}Node;

Node* ar[100010];
Node* tail[100010];	//記住每一行tail node的位置讓存取更快 

int main(void)
{
	int i;
	int row,size;
	int q,type,a,b;
	
	scanf("%d",&row);
	for(i=0;i<row;i++){
		scanf("%d",&size);
		if(size!=0){
			Node* newnode=(Node*)malloc(sizeof(Node));
			
			char* str=(char*)malloc(sizeof(char) * (size+5));
			scanf("%s",str);
			
			newnode->str=str;
			newnode->next=NULL;
			
			ar[i]=tail[i]=newnode;
		}else{
			ar[i]=tail[i]=NULL;
		}
	}
	
	scanf("%d",&q);
	for(i=0;i<q;i++){
		scanf("%d%d%d",&type,&a,&b);	//注意1<=a,b<=N
		a-=1,b-=1;
		if(type==1){	//a搬到b的前面
			if(ar[a]!=NULL){
				if(ar[b]==NULL){	//注意tail也要更新 
					ar[b]=ar[a],tail[b]=tail[a];
					ar[a]=tail[a]=NULL;
				}else{
					tail[a]->next=ar[b];	//a row的尾巴連接b row的開頭
					
					//兩行指標交換，記得更新tail
					ar[b]=ar[a];
					ar[a]=tail[a]=NULL;
				}
			}
		}else if(type==2){	//a搬到b的後面
			if(ar[a]!=NULL){
				if(ar[b]==NULL){	//注意tail也要更新 
					ar[b]=ar[a],tail[b]=tail[a];
					ar[a]=tail[a]=NULL;
				}else{
					tail[b]->next=ar[a];	//b的尾巴連接a的開頭 
					tail[b]=tail[a];	//記得更新tail
					ar[a]=tail[a]=NULL;
				}
			}
		}else if(type==3){	//ab行交換 
			if(ar[a]==NULL && ar[b]==NULL){
				continue;
			}else{
				//指標交換 
				Node* tmp=ar[a];
				ar[a]=ar[b];
				ar[b]=tmp;
				
				//注意tail也要交換
				Node* tail_tmp=tail[a];
				tail[a]=tail[b];
				tail[b]=tail_tmp;
			}
		}
	}
	
	for(i=0;i<row;i++){
		if(ar[i]!=NULL){
			Node* now=ar[i];
			while(now!=NULL){
				printf("%s",now->str);
				now=now->next;
			}
		}
		printf("\n");
	}
	
	//釋放記憶體 
	for(i=0;i<row;i++){
		if(ar[i]!=NULL){
			Node *tmp=ar[i],*now=ar[i];	//從第一個node開始出發 
			while(now!=NULL){
				now=now->next;	//now先移動 
				free(tmp->str);
				free(tmp);
				tmp=now;	//tmp移到now的位置 
			}
		}
	}
	return 0;
}
