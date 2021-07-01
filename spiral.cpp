#include<stdio.h>
int main(void)
{
	int i,j,k;
	int index,cur;
	int di[4]={0,1,0,-1},dj[4]={1,0,-1,0};//right,down,left,up
	
	int t,n;
	
	scanf("%d",&t);	
	for(i=0;i<t;i++){//t次
	
		scanf("%d",&n);
		char a[n][n];
		for(j=0;j<n;j++)
			for(k=0;k<n;k++)
				a[j][k]=' ';
			
		
		int start_i=0,start_j=-1;//一開始從[0][-1]出發 
		index=0;
		cur=n;//用cur記住現在需要走的步數n 
		
		while(cur>0)
		{ 
			for(j=0;j<cur;j++){
				start_i+=di[index];
				start_j+=dj[index];
				a[ start_i ][ start_j ]='#';			
			}			
			index=(index+1)%4;	//index要記得mod 
			cur--;		
		}		
		
		//printf("cur=%d,b[i]=%d",cur,b[i]);
		for(j=0;j<n;j++){
			for(k=0;k<n;k++){
				if(a[j][k]!='#'){
					a[j][k]=' ';//順便清空地圖 
					printf("%c",a[j][k]);
				}else{
					printf("%c",a[j][k]);
					a[j][k]=' ';//順便清空地圖
				}
			}
			printf("\n");
		}
		
	}	
	return 0;
}
