#include<stdio.h>
int dish[1000000]={0};
int main(void)
{
	int n,q,l,r;
	int i,j,k;
	
	scanf("%d%d",&n,&q);
	
	int record[32][n];	//建表，以後用來查詢 
	
	for(i=0;i<n;i++)
		scanf("%d",&dish[i]);
	
	
	for(i=0;i<32;i++){	//表中的第0個col先填入數字 
		if(dish[0]==i){
			record[i][0]=1;
		}else{
			record[i][0]=0;
		}
	}
	
	for(i=0;i<32;i++){
		for(j=1;j<n;j++){
			if(dish[j]==i){		//如果dish[j]這個數字是i，就把表的i-th row,j-th的位置=前一格+1 
				record[i][j]=record[i][j-1]+1;
			}else{
				record[i][j]=record[i][j-1];	//否則就延續前面一格的數字
			}
		}
	}
	
	for(i=0;i<q;i++){
		scanf("%d%d",&l,&r);
		int count=0;
		for(j=0;j<32;j++){
			if(l==0){	//如果左端點是0 
				if(record[j][r]!=0){	//那就只需要比右端點的數字有沒有增加過 
					count++;
				}
			}else{			
				if(record[j][l-1]!=record[j][r]){	//如果左端點的數字跟右端點的數字不一樣，就代表這個數字有出現過-->count+1; 
					count++;
				}
			}
		}
		printf("%d\n",count);
	}
	return 0;
}
