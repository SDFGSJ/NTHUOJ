#include<stdio.h>
int Fplace[20000]={0};//�ΨӰO���f�r�y�� 
int main(void)
{
	int row,col,time;
	int i,j,k,l,count=0;//i,j,k,l�j���ܼ� 
	char a[105][105]={'\0'};
	
	scanf("%d%d%d",&row,&col,&time);	
	for(i=0;i<row;i++)
		scanf("%s",&a[i]);
		
	k=0;
	while(k<time)
	{
		count=0;//�C�����y�f�r�e���n��count�k0�A�o�ˤ~�|�����s��Fplace�i�H�ΡA�]���|��runtime error 
		//���y�f�r 
		for(i=0;i<row;i++){
			for(j=0;j<col;j++){
				if(a[i][j]=='F'){
					//printf("%d,%d\n",i,j);
					Fplace[count]=i;
					Fplace[count+1]=j;
					count+=2;//�]���O�@���}�C										
				}			
			}						
		}
		
		for(l=0;l<count;l+=2){		
			if(a[ Fplace[l]-1 ][ Fplace[l+1]   ]=='C')	a[ Fplace[l]-1 ][ Fplace[l+1]   ]='F';//up
			if(a[ Fplace[l]+1 ][ Fplace[l+1]   ]=='C')	a[ Fplace[l]+1 ][ Fplace[l+1]   ]='F';//down
			if(a[ Fplace[l]   ][ Fplace[l+1]-1 ]=='C')	a[ Fplace[l]   ][ Fplace[l+1]-1 ]='F';//left
			if(a[ Fplace[l]   ][ Fplace[l+1]+1 ]=='C')	a[ Fplace[l]   ][ Fplace[l+1]+1 ]='F';//right						
		}
		k++;
		//printf("count=%d\n",count);
	}						
	
	/*for(i=0;i<10;i++)
		printf("%d ",Fplace[i]);*/
	
	//�L�X��						
	for(i=0;i<row;i++){
		for(j=0;j<col;j++){
			printf("%c",a[i][j]);
		}
		if(j!=col-1)
			printf("\n");
	}
																				
	return 0;
}
