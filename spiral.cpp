#include<stdio.h>
int main(void)
{
	int i,j,k;
	int index,cur;
	int di[4]={0,1,0,-1},dj[4]={1,0,-1,0};//right,down,left,up
	
	int t,n;
	
	scanf("%d",&t);	
	for(i=0;i<t;i++){//t��
	
		scanf("%d",&n);
		char a[n][n];
		for(j=0;j<n;j++)
			for(k=0;k<n;k++)
				a[j][k]=' ';
			
		
		int start_i=0,start_j=-1;//�@�}�l�q[0][-1]�X�o 
		index=0;
		cur=n;//��cur�O��{�b�ݭn�����B��n 
		
		while(cur>0)
		{ 
			for(j=0;j<cur;j++){
				start_i+=di[index];
				start_j+=dj[index];
				a[ start_i ][ start_j ]='#';			
			}			
			index=(index+1)%4;	//index�n�O�omod 
			cur--;		
		}		
		
		//printf("cur=%d,b[i]=%d",cur,b[i]);
		for(j=0;j<n;j++){
			for(k=0;k<n;k++){
				if(a[j][k]!='#'){
					a[j][k]=' ';//���K�M�Ŧa�� 
					printf("%c",a[j][k]);
				}else{
					printf("%c",a[j][k]);
					a[j][k]=' ';//���K�M�Ŧa��
				}
			}
			printf("\n");
		}
		
	}	
	return 0;
}
