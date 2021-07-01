#include<stdio.h>
#include<stdlib.h>
typedef struct _Node{
    int size;	//the stack size
    int* data;	//points to an array
    struct _Node* next;
}Node;

Node* ReadOneList();
void PrintList(Node*);
void Merge(Node*,int,int);
void Cut(Node*,int,int);

int main(){
    Node* dummy_head;
    Node* tail;

    dummy_head=(Node*)malloc(sizeof(Node));
    dummy_head->data=NULL;
    dummy_head->size=-1;

    tail=dummy_head;

    int N,M;
    scanf("%d%d",&N,&M);
    for(int i=0;i<N;i++){
        tail->next=ReadOneList();
        tail=tail->next;   
    }
    /*printf("debug:\n");
    Node* test=dummy_head->next;
    for(int i=0;i<N;i++){
    	for(int j=0;j<test->size;j++){
    		printf("%d,",test->data[j]);
		}
		printf("\n");
		test=test->next;
	}*/
    char act[10];
    int x,y;
    for(int i=0;i<M;i++){
        scanf("%s%d%d",act,&x,&y);
        if(act[0]=='M'){
            Merge(dummy_head,x,y);
        }else{
            Cut(dummy_head,x,y);
        }
    }
    PrintList(dummy_head);
    return 0;
}
Node* ReadOneList()
{
	int i;
	
	//�إߤ@��node 
	Node* newnode=(Node*)malloc(sizeof(Node));
	
	//�إ߰}�C 
	int array_size;
	scanf("%d:",&array_size);
	int* array=(int*)malloc(sizeof(int)*array_size);
	for(i=0;i<array_size;i++){
		scanf("%d",&array[i]);
	}
	
	//���� 
	newnode->data=array;
	newnode->size=array_size;
	newnode->next=NULL;	//�o�@�B�i�H��list���̫����NULL 
	
	return newnode;
}
void PrintList(Node* head)
{
	int i;
	
	//move to the first node
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
void Merge(Node* dummy_head, int from, int to)	//put the from card stack on the top of to card stack
{	
	/*dont free the node*/
	int i;
	Node *stack_from=dummy_head,*stack_to=dummy_head;
	//�����node 
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
	//�إߤ@�ӷs��array 
	int new_array_size=stack_from->size+stack_to->size;	
	int* new_array=(int*)malloc(sizeof(int)*new_array_size);
	
	//����to�b��from
	for(i=0;i<stack_to->size;i++){
		new_array[i]=(stack_to->data)[i];
	}
	for(i=stack_to->size;i<new_array_size;i++){
		new_array[i]=(stack_from->data)[i-(stack_to->size)];
	}
	
	/*printf("debug:");
	for(i=0;i<new_array_size;i++){
		printf("%d,",new_array[i]);
	}
	printf("\n");*/
	
	//�ᱼfrom���°}�C
	free(stack_from->data);
	stack_from->data=NULL;
	//�ᱼto���°}�C�ñNdata���VNULL
	free(stack_to->data);
	stack_to->data=NULL;
	//��sto����T 
	stack_to->size=new_array_size;
	stack_to->data=new_array;
}
void Cut(Node* dummy_head, int x, int i)	//cut the x-th card stack into two stacks: (1~i)�Bremaining 
{
	/*dont free the node*/
	int j;
	Node* stack_x=dummy_head;
	//�إߤ@��node 
	Node* newnode=(Node*)malloc(sizeof(Node));
	//�����node 
	while(x--){
		stack_x=stack_x->next;
		if(stack_x->data==NULL){
			x++;
		}
	}
	//�ݭn��ӷs���}�C�Ӧs����Ϋ᪺�� 
	int* origin_ar=(int*)malloc(sizeof(int)*i);
	int* remaining_ar=(int*)malloc(sizeof(int)*(stack_x->size-i));
	//�ۼƦr 
	for(j=0;j<i;j++){
		origin_ar[j]=(stack_x->data)[j];
	}
	for(j=0;j<(stack_x->size)-i;j++){
		remaining_ar[j]=(stack_x->data)[i+j];
	}
	//�ۧ��Ʀr����N�ᱼx���°}�C�ñNdata���VNULL
	free(stack_x->data);
	stack_x->data=NULL;
	//�Nnewnode�[��list�̭�
	if(stack_x->next==NULL){	//�p�G���Ϊ��O�̫�@��node 
		newnode->next=NULL;
		//tail=newnode;	//renew the tail node
		//newnode->next=NULL;
	}else{
		newnode->next=stack_x->next;
	}
	stack_x->next=newnode;
	//�N���array��node�s���_��
	stack_x->data=origin_ar;
	newnode->data=remaining_ar;
	//��snode����T 
	//�`�N�n����snewnode->size�A�]���p�G�����stack_x->size�|��
	newnode->size=(stack_x->size)-i;
	stack_x->size=i;
}
