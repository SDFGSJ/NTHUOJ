#include<stdio.h>
int dish[1000000]={0};
int main(void)
{
	int n,q,l,r;
	int i,j,k;
	
	scanf("%d%d",&n,&q);
	
	int record[32][n];	//�ت�A�H��ΨӬd�� 
	
	for(i=0;i<n;i++)
		scanf("%d",&dish[i]);
	
	
	for(i=0;i<32;i++){	//������0��col����J�Ʀr 
		if(dish[0]==i){
			record[i][0]=1;
		}else{
			record[i][0]=0;
		}
	}
	
	for(i=0;i<32;i++){
		for(j=1;j<n;j++){
			if(dish[j]==i){		//�p�Gdish[j]�o�ӼƦr�Oi�A�N���i-th row,j-th����m=�e�@��+1 
				record[i][j]=record[i][j-1]+1;
			}else{
				record[i][j]=record[i][j-1];	//�_�h�N����e���@�檺�Ʀr
			}
		}
	}
	
	for(i=0;i<q;i++){
		scanf("%d%d",&l,&r);
		int count=0;
		for(j=0;j<32;j++){
			if(l==0){	//�p�G�����I�O0 
				if(record[j][r]!=0){	//���N�u�ݭn��k���I���Ʀr���S���W�[�L 
					count++;
				}
			}else{			
				if(record[j][l-1]!=record[j][r]){	//�p�G�����I���Ʀr��k���I���Ʀr���@�ˡA�N�N��o�ӼƦr���X�{�L-->count+1; 
					count++;
				}
			}
		}
		printf("%d\n",count);
	}
	return 0;
}
