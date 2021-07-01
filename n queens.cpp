#include<stdio.h>
int n,count=0;
int q[20];	//記錄queen所在的col 

void place(int);
//void display();
int valid(int,int);

int main(void)
{
	scanf("%d",&n);
	
	place(0);	//從[0][0]開始放 
		
	/*for(int i=0;i<n;i++){
		printf("%d",q[i]);
	}*/
	
	printf("%d",count);
	return 0;
}
void place(int row)
{
	int i;
	if(row==n){		//如果已經擺到最後一行，就代表我們已經找到一種解答 
		count++;
		//display();
	}else{
		for(i=0;i<n;i++){
			if( valid(row,i) ){		//在放之前要先確認該位置能不能放 
				q[row]=i;	//如果可以放，先把位置記錄下來再來放置 
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
	for(i=0;i<row;i++){		//從第一個棋子開始檢查有沒有衝突 
		if(q[i]==col || q[i]-col==row-i || q[i]-col==i-row){
			return 0;	//這裡不可以用if(...) ok=0 else ok=1，因為在放皇后的時候就只跟最後一個有關了 
		}
	}
	return 1;
}
