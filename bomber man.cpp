#include<stdio.h>
int main(void)
{	
	int i,j,bomb[2]={-1,-1},index=0,temp_row,temp_col;
	char a[6][6];
	for(i=0;i<6;i++)
		for(j=0;j<6;j++)
			scanf("%s",&a[i][j]);
	
	for(i=0;i<6;i++)
		for(j=0;j<6;j++)
		{
			if(a[i][j]=='o'){//°O¿ý¬µ¼u¦ì¸m 
				bomb[0]=i;
				bomb[1]=j;
			}						
		}
		
	if(bomb[0]==-1 && bomb[1]==-1){
		for(i=0;i<6;i++){
			for(j=0;j<6;j++){
				if(j!=5)
					printf("%c ",a[i][j]);
				else
					printf("%c\n",a[i][j]);	
			}				
		}
	}else{
		temp_row=bomb[0];
		temp_col=bomb[1];
		while(a[temp_row][temp_col-1]!='x' && temp_col>0){//left
			a[temp_row][temp_col-1]='=';
			temp_col--;
		}
		
		temp_row=bomb[0];
		temp_col=bomb[1];
		while(a[temp_row-1][temp_col]!='x' && temp_row>0){//up
			a[temp_row-1][temp_col]='=';
			temp_row--;
		}
		
		temp_row=bomb[0];
		temp_col=bomb[1];
		while(a[temp_row][temp_col+1]!='x' && temp_col<5){//right
			a[temp_row][temp_col+1]='=';
			temp_col++;
		}
		
		temp_row=bomb[0];
		temp_col=bomb[1];
		while(a[temp_row+1][temp_col]!='x' && temp_row<5){//down
			a[temp_row+1][temp_col]='=';
			temp_row++;
		}
			
		for(i=0;i<6;i++){
			for(j=0;j<6;j++){
				if(j!=5)
					printf("%c ",a[i][j]);
				else
					printf("%c\n",a[i][j]);	
			}				
		}
	}
	return 0;
}
