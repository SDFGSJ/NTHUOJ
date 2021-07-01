#include<stdio.h>
int main(void)
{
	/*
	m,n:列,行
	k次操作
	i,j,l:迴圈變數
	temp:交換用 
	sum:每個row的平方和的變數
	max_len:記錄row的最大長度
	max_row:記錄擁有最大長度是哪個row
	*/
    int m,n,k,i,j,l,temp,sum,max_len=0,max_row=0;
	scanf("%d%d%d",&m,&n,&k);
	//mat:原始陣列，op:操作陣列 
    int mat[m][n],op[k][3];
    //讀取原始陣列 
    for(i=0;i<m;i++)
    {
        for(j=0;j<n;j++)        
            scanf("%d",&mat[i][j]);   
    }
    //讀取操作陣列+判斷是何種操作並進行運算 
    for(i=0;i<k;i++)
    {
        for(j=0;j<3;j++){
        	scanf("%d",&op[i][j]);	 
		}
		for(l=0;l<n;l++)
		{
			if(op[i][0]==0){
				//switch						
				temp=mat[ op[i][1] ][l];
				mat[ op[i][1] ][l]=mat[ op[i][2] ][l];
				mat[ op[i][2] ][l]=temp;			       
    		}else{
    			//add(i,j)-->i+=j    		    		
    			mat[ op[i][1] ][l]+=mat[ op[i][2] ][l];			
			}
		} 		
    }

	/*印出陣列(實驗用)
	for(i=0;i<m;i++)
	{
	    for(j=0;j<n;j++){
	        printf("%d ",mat[i][j]);
		}
		printf("\n");                       
	}*/  
	
	//計算該row的長度 
	for(i=0;i<m;i++)
	{
		sum=0;//每次計算新的row前，先把sum的值歸0 
		for(j=0;j<n;j++)
		{
			sum+=mat[i][j]*mat[i][j];//平方加總			
		}
		if(sum>=max_len)//如果現在算的那個row長度比目前最大的還要大 
		{
			max_len=sum;//把現在的sum指定給max_len 
			max_row=i;//記住擁有max_len的是第幾列 
		}
		//printf("row=%d,sum=%d\n",i,sum);
	}
	//printf("(row,max_len)=%d,%d",max_row,max_len);
	//印出擁有max_len的那一列的所有成員 
	for(i=0;i<n-1;i++)
	{
		printf("%d ",mat[max_row][i]);
	}
	printf("%d\n",mat[max_row][n-1]);
    return 0;
}
