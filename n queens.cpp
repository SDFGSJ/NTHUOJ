#include<stdio.h>
int n,count=0;
int q[20];	//�O��queen�Ҧb��col 

void place(int);
//void display();
int valid(int,int);

int main(void)
{
	scanf("%d",&n);
	
	place(0);	//�q[0][0]�}�l�� 
		
	/*for(int i=0;i<n;i++){
		printf("%d",q[i]);
	}*/
	
	printf("%d",count);
	return 0;
}
void place(int row)
{
	int i;
	if(row==n){		//�p�G�w�g�\��̫�@��A�N�N��ڭ̤w�g���@�ظѵ� 
		count++;
		//display();
	}else{
		for(i=0;i<n;i++){
			if( valid(row,i) ){		//�b�񤧫e�n���T�{�Ӧ�m�ण��� 
				q[row]=i;	//�p�G�i�H��A�����m�O���U�ӦA�ө�m 
				place(row+1);
			}
		}	
	}
}
/*
void display()
{
	int i,j;
	for(i=0;i<n;i++){
		for(j=0;j<n;j++){
			if(j==q[i]){
				printf("o");
			}else{
				printf("x");
			}
		}
		printf("\n");
	}
	printf("\n-------\n");
}
*/
int valid(int row,int col)
{
	int i;
	for(i=0;i<row;i++){		//�q�Ĥ@�ӴѤl�}�l�ˬd���S���Ĭ� 
		if(q[i]==col || q[i]-col==row-i || q[i]-col==i-row){
			return 0;	//�o�̤��i�H��if(...) ok=0 else ok=1�A�]���b��ӦZ���ɭԴN�u��̫�@�Ӧ����F 
		}
	}
	return 1;
}
