#include<stdio.h>
int main(void)
{
	/*
	m,n:�C,��
	k���ާ@
	i,j,l:�j���ܼ�
	temp:�洫�� 
	sum:�C��row������M���ܼ�
	max_len:�O��row���̤j����
	max_row:�O���֦��̤j���׬O����row
	*/
    int m,n,k,i,j,l,temp,sum,max_len=0,max_row=0;
	scanf("%d%d%d",&m,&n,&k);
	//mat:��l�}�C�Aop:�ާ@�}�C 
    int mat[m][n],op[k][3];
    //Ū����l�}�C 
    for(i=0;i<m;i++)
    {
        for(j=0;j<n;j++)        
            scanf("%d",&mat[i][j]);   
    }
    //Ū���ާ@�}�C+�P�_�O��ؾާ@�öi��B�� 
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

	/*�L�X�}�C(�����)
	for(i=0;i<m;i++)
	{
	    for(j=0;j<n;j++){
	        printf("%d ",mat[i][j]);
		}
		printf("\n");                       
	}*/  
	
	//�p���row������ 
	for(i=0;i<m;i++)
	{
		sum=0;//�C���p��s��row�e�A����sum�����k0 
		for(j=0;j<n;j++)
		{
			sum+=mat[i][j]*mat[i][j];//����[�`			
		}
		if(sum>=max_len)//�p�G�{�b�⪺����row���פ�ثe�̤j���٭n�j 
		{
			max_len=sum;//��{�b��sum���w��max_len 
			max_row=i;//�O��֦�max_len���O�ĴX�C 
		}
		//printf("row=%d,sum=%d\n",i,sum);
	}
	//printf("(row,max_len)=%d,%d",max_row,max_len);
	//�L�X�֦�max_len�����@�C���Ҧ����� 
	for(i=0;i<n-1;i++)
	{
		printf("%d ",mat[max_row][i]);
	}
	printf("%d\n",mat[max_row][n-1]);
    return 0;
}
