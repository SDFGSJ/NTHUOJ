#include<stdio.h>
char a[50][50];
int main(void)
{
	int n,m,touch=0,clear=0;
	int i,j,k;
	scanf("%d%d",&n,&m);
	
	for(i=0;i<n;i++){
		scanf("%s",a[i]);
	}
	
	while(1)
	{
		//檢查有沒有touch 
		for(i=0;i<n;i++){
			for(j=0;j<m;j++){
				if(a[i][j]=='o'){
					if(i==n-1 || a[i+1][j]=='x'){	//只要'o'碰到底或是'o'下面是'x'，則touch改成1表示碰到 
						touch=1;
					}
				}
			}
		}
		
		if(touch)	break;	//如果碰到了，就跳離迴圈，不用做下面的'o'下移 
		
		for(i=n-1;i>=0;i--){	//從底下的'o'開始做 
			for(j=0;j<m;j++){
				if(a[i][j]=='o'){
					a[i+1][j]='o';
					a[i][j]='.';
				}
			}
		}
	}
	
	for(i=n-1;i>=0;i--){
		clear=1;	//先假設每一行都可以消除 
		for(j=0;j<m;j++){
			if(a[i][j]=='.'){	//如果掃到了'.'，就代表這行不能消掉，clear設成0 
				clear=0;
			}else if(a[i][j]=='o'){		//如果是'o'就順便改成'x' 
				a[i][j]='x';
			}
		}
		if(clear){
			for(j=i;j>=1;j--){
				for(k=0;k<m;k++){
					a[j][k]=a[j-1][k];
				}
			}
			for(j=0;j<m;j++){	//第一行一直更新為'.' 
				a[0][j]='.';
			}
			i++;	//為了讓每一次檢查都從最後一行開始 
		}
	}
	
	for(i=0;i<n;i++){
		for(j=0;j<m;j++){
			printf("%c",a[i][j]);
		}
		printf("\n");
	}
	return 0;
}
