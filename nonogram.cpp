#include<stdio.h>
char a[50][50];		//�O���a�� 
int len_row[50]={0};//�O���Crow���Ʀr�Ӽ� 
int len_col[50]={0};//�O���Ccol���Ʀr�Ӽ�
int row[50][50]={0};//�O��row��'o'�������p 
int col[50][50]={0};//�O��col��'o'�������p

int main(void)
{
	int n,m,t;
	int count=0,sum=0;
	int i,j,k;
	
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d%d",&n,&m);	//n*m���a�� 
		
		for(i=0;i<n;i++){
			scanf("%d",&len_row[i]);
			for(j=0;j<len_row[i];j++){
				scanf("%d",&row[i][j]);
			}
		}
		
		for(i=0;i<m;i++){
			scanf("%d",&len_col[i]);
			for(j=0;j<len_col[i];j++){
				scanf("%d",&col[i][j]);
			}
		}
		
		for(i=0;i<n;i++)
			scanf("%s",a[i]);
		
		
		int valid=1;
		for(i=0;i<n;i++){	//row
			int index=0,count=0;
			for(j=0;j<=m;j++){	//j�n�����h�]�@��A�]���p�G�̫�@�ӬO'o'�A�ٻݭn�A�]�@���A�ˬd�����S���ŦX�������p 
				if(j!=m && a[i][j]=='o'){	//�u�nj�٨S��̫�ӥBa[i][j]=='o' 
					count++;
				}else if(count>0){	//j==m �� a[i][j]=='x'�N�]else if�o��A�p�G�{�b'o'�Ӽ�>0 
					if(index>=len_row[i]){	//�p�G���Ӧh��'o'�Aindex�N�|�W�L��row���Ʀr�Ӽ� --> �L��
						valid=0;
					}else if(count!=row[i][index]){		//�p�G�ثe'o'�ӼƸ�������p���@�� --> �L�� 
						valid=0;
					}
					index++;
					count=0;
				}
			}
			if(index!=len_row[i])	valid=0;	//�p�Gindex�������row���Ʀr�Ӽ�-->�L�� 
		}
		
		for(i=0;i<m;i++){	//col	//�`�Ni�q0��m-1 
			int index=0,count=0;
			for(j=0;j<=n;j++){	//�`�Nj�q0��n�Aj�n�h�]�@��A�]���p�G�̫�@�ӬO'o'�A�ٻݭn�A�]�@���A�ˬd�����S���ŦX�������p
				if(j!=n && a[j][i]=='o'){	//�`�N�Oa[j][i]���Oa[i][j] 
					count++;
				}else if(count>0){	//j==n �� a[j][i]=='x'�N�]else if�o��A�p�G�{�b'o'�Ӽ�>0
					if(index>=len_col[i]){
						valid=0;
					}else if(count!=col[i][index]){		//�p�G�ثe'o'�ӼƸ�������p���@��-->�L��
						valid=0;
					}
					index++;
					count=0;
				}
			}
			if(index!=len_col[i])	valid=0;	//�p�Gindex�������row���Ʀr�Ӽ�-->�L��
		}
		
		
		if(valid)
			printf("Yes\n");
		else
			printf("No\n");
//-----------------------------------------------------------
		/*
		printf("len_row[]=");
		for(i=0;i<n;i++){
			printf("%d",len_row[i]);
		}
		
		printf("\nlen_col[]=");
		for(i=0;i<m;i++){
			printf("%d",len_col[i]);
		}
		
		printf("\nrow[]=\n");
		for(i=0;i<n;i++){
			for(j=0;j<m;j++){
				printf("%d",row[i][j]);
			}
			printf("\n");
		}
		
		printf("\ncol[]=\n");
		for(i=0;i<n;i++){
			for(j=0;j<m;j++){
				printf("%d",col[i][j]);
			}
			printf("\n");
		}		
		*/
	}
	return 0;
}
