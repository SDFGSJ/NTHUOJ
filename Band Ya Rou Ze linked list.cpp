#include<stdio.h>
#include<stdlib.h>
typedef struct _node{
	char* str;
	struct _node* next;
}Node;

Node* ar[100010];
Node* tail[100010];	//�O��C�@��tail node����m���s����� 

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
		scanf("%d%d%d",&type,&a,&b);	//�`�N1<=a,b<=N
		a-=1,b-=1;
		if(type==1){	//a�h��b���e��
			if(ar[a]!=NULL){
				if(ar[b]==NULL){	//�`�Ntail�]�n��s 
					ar[b]=ar[a],tail[b]=tail[a];
					ar[a]=tail[a]=NULL;
				}else{
					tail[a]->next=ar[b];	//a row�����ڳs��b row���}�Y
					
					//�����Х洫�A�O�o��stail
					ar[b]=ar[a];
					ar[a]=tail[a]=NULL;
				}
			}
		}else if(type==2){	//a�h��b���᭱
			if(ar[a]!=NULL){
				if(ar[b]==NULL){	//�`�Ntail�]�n��s 
					ar[b]=ar[a],tail[b]=tail[a];
					ar[a]=tail[a]=NULL;
				}else{
					tail[b]->next=ar[a];	//b�����ڳs��a���}�Y 
					tail[b]=tail[a];	//�O�o��stail
					ar[a]=tail[a]=NULL;
				}
			}
		}else if(type==3){	//ab��洫 
			if(ar[a]==NULL && ar[b]==NULL){
				continue;
			}else{
				//���Х洫 
				Node* tmp=ar[a];
				ar[a]=ar[b];
				ar[b]=tmp;
				
				//�`�Ntail�]�n�洫
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
	
	//����O���� 
	for(i=0;i<row;i++){
		if(ar[i]!=NULL){
			Node *tmp=ar[i],*now=ar[i];	//�q�Ĥ@��node�}�l�X�o 
			while(now!=NULL){
				now=now->next;	//now������ 
				free(tmp->str);
				free(tmp);
				tmp=now;	//tmp����now����m 
			}
		}
	}
	return 0;
}
