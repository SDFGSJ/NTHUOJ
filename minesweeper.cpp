#include<stdio.h>
int main(void)
{
	char a[11][11]={0};
	int i,j,k,l;
	for(i=1;i<=9;i++)
		for(j=1;j<=9;j++)
			scanf("%s",&a[i][j]);
	for(i=1;i<=9;i++)
	{
		for(j=1;j<=9;j++)
		{
				if(a[i][j]=='x'){
					for(k=i-1;k<=i+1;k++){
						for(l=j-1;l<=j+1;l++){
							if(a[k][l]=='x'){
								a[k][l]='x';
							}else if(a[k][l]=='_'){
								a[k][l]='1';
							}else{
								a[k][l]++; 
							}
						}
					}
				}
		}
	}
	for(i=1;i<=9;i++){
		for(j=1;j<=9;j++){
			if(j!=9)
				printf("%c ",a[i][j]);
			else
				printf("%c\n",a[i][j]);	
		}
	}						
	return 0;
}
