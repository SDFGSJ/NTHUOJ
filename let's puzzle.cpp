#include<stdio.h>
char board[50][50];	//�ѽL 
char piece[50][50];	//���� 

int main(void)
{
	int n,m,x,y;	//n,m:�ѽL�ؤo	x,y:���Ϥؤo 
	int i,j,k,l;
	int test,flag=0,ans=0;	//flag:�ˬd�i���i�H���i�h		ans:�ˬd�{�b���S������ 
	
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
				flag=1;	//���]�@�}�l�i�H���i�h 
				for(k=0;k<x;k++){
					for(l=0;l<y;l++){
						//����gboard[i+k][j+l]=='#'����:(2/5) 
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
