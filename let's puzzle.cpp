#include<stdio.h>
char board[50][50];	//棋盤 
char piece[50][50];	//拼圖 

int main(void)
{
	int n,m,x,y;	//n,m:棋盤尺寸	x,y:拼圖尺寸 
	int i,j,k,l;
	int test,flag=0,ans=0;	//flag:檢查可不可以拼進去		ans:檢查現在有沒有答案 
	
	scanf("%d%d",&n,&m);
	for(i=0;i<n;i++){
		scanf("%s",board[i]);
	}
	
	scanf("%d",&test);
	while(test--)
	{
		ans=0;
		scanf("%d%d",&x,&y);
		for(i=0;i<x;i++){
			scanf("%s",piece[i]);
		}
		
		for(i=0;i<n;i++){
			for(j=0;j<m;j++){
				flag=1;	//假設一開始可以拼進去 
				for(k=0;k<x;k++){
					for(l=0;l<y;l++){
						//不能寫board[i+k][j+l]=='#'測資:(2/5) 
						if(board[i+k][j+l]!='o' && piece[k][l]=='#'){
							flag=0;
						}
					}
				}
				if(flag)	ans=1;
			}
		}
		if(ans)
			printf("Yes\n");
		else
			printf("No\n");
	}
	return 0;
}
