#include<stdio.h>
int main(void)
{
	int row,col,time;
	int i,j,k=0;
	char a[105][105]={'\0'};
	scanf("%d%d%d",&row,&col,&time);
	
	for(i=0;i<row;i++){
		for(j=0;j<=col;j++){
			scanf("%c",&a[i][j]);
		}
	}
	
	for(i=0;i<row;i++){
		for(j=0;j<=col;j++){
			printf("%c",a[i][j]);
		}
	}
	
	//°O¿ýFªº¦ì¸m 
	for(i=0;i<row;i++){
		for(j=0;j<col;j++){
			if(a[i][j]=='F'){
				printf("(%d,%d)\n",i,j);
				while(k<time){
					if(a[i-1][j-1]!='#')
						a[i-1][j-1]='F';//up
					if(a[i+1][j-1]!='#')
						a[i+1][j-1]='F';//down
					if(a[i][j-2]!='#')
						a[i][j-2]='F';//left
					if(a[i][j-1]!='#')
						a[i][j-1]='F';//right
					k++;
				}		
			}
		}
	}
	
	/*for(i=0;i<row;i++){
		for(j=0;j<=col;j++){
			printf("%c",a[i][j]);
		}
	}*/
	
	return 0;
}
