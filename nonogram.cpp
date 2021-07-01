#include<stdio.h>
char a[50][50];		//記錄地圖 
int len_row[50]={0};//記錄每row的數字個數 
int len_col[50]={0};//記錄每col的數字個數
int row[50][50]={0};//記錄row的'o'分布狀況 
int col[50][50]={0};//記錄col的'o'分布狀況

int main(void)
{
	int n,m,t;
	int count=0,sum=0;
	int i,j,k;
	
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d%d",&n,&m);	//n*m的地圖 
		
		for(i=0;i<n;i++){
			scanf("%d",&len_row[i]);
			for(j=0;j<len_row[i];j++){
				scanf("%d",&row[i][j]);
			}
		}
		
		for(i=0;i<m;i++){
			scanf("%d",&len_col[i]);
			for(j=0;j<len_col[i];j++){
				scanf("%d",&col[i][j]);
			}
		}
		
		for(i=0;i<n;i++)
			scanf("%s",a[i]);
		
		
		int valid=1;
		for(i=0;i<n;i++){	//row
			int index=0,count=0;
			for(j=0;j<=m;j++){	//j要讓它多跑一圈，因為如果最後一個是'o'，還需要再跑一次，檢查它有沒有符合分布狀況 
				if(j!=m && a[i][j]=='o'){	//只要j還沒到最後而且a[i][j]=='o' 
					count++;
				}else if(count>0){	//j==m 或 a[i][j]=='x'就跑else if這邊，如果現在'o'個數>0 
					if(index>=len_row[i]){	//如果算到太多組'o'，index就會超過該row的數字個數 --> 無效
						valid=0;
					}else if(count!=row[i][index]){		//如果目前'o'個數跟分布狀況不一樣 --> 無效 
						valid=0;
					}
					index++;
					count=0;
				}
			}
			if(index!=len_row[i])	valid=0;	//如果index不等於該row的數字個數-->無效 
		}
		
		for(i=0;i<m;i++){	//col	//注意i從0到m-1 
			int index=0,count=0;
			for(j=0;j<=n;j++){	//注意j從0到n，j要多跑一圈，因為如果最後一個是'o'，還需要再跑一次，檢查它有沒有符合分布狀況
				if(j!=n && a[j][i]=='o'){	//注意是a[j][i]不是a[i][j] 
					count++;
				}else if(count>0){	//j==n 或 a[j][i]=='x'就跑else if這邊，如果現在'o'個數>0
					if(index>=len_col[i]){
						valid=0;
					}else if(count!=col[i][index]){		//如果目前'o'個數跟分布狀況不一樣-->無效
						valid=0;
					}
					index++;
					count=0;
				}
			}
			if(index!=len_col[i])	valid=0;	//如果index不等於該row的數字個數-->無效
		}
		
		
		if(valid)
			printf("Yes\n");
		else
			printf("No\n");
//-----------------------------------------------------------
		/*
		printf("len_row[]=");
		for(i=0;i<n;i++){
			printf("%d",len_row[i]);
		}
		
		printf("\nlen_col[]=");
		for(i=0;i<m;i++){
			printf("%d",len_col[i]);
		}
		
		printf("\nrow[]=\n");
		for(i=0;i<n;i++){
			for(j=0;j<m;j++){
				printf("%d",row[i][j]);
			}
			printf("\n");
		}
		
		printf("\ncol[]=\n");
		for(i=0;i<n;i++){
			for(j=0;j<m;j++){
				printf("%d",col[i][j]);
			}
			printf("\n");
		}		
		*/
	}
	return 0;
}
