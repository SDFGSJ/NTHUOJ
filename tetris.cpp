#include<stdio.h>	//������� 
int cir[1600][2]={0};
char a[45][45];
int main(void)
{
	int n,m;
	int touch=0;//�ˬd'o'���S���I��'x'�Φa�O
	int i,j,k,l;
	scanf("%d%d",&n,&m);
				
	for(i=0;i<n;i++)
		scanf("%s",a[i]);
	

	for(int z=0;touch!=1;z++){
			
		//�O��'o'����m
		int index=0;
		for(i=0;i<n;i++){	 
			for(j=0;j<m;j++){
				if(a[i][j]=='o'){
					//printf("(%d,%d)\n",i,j);
					cir[index][0]=i;
					cir[index][1]=j;
					//�p�G���U���O'x'�Ϊ̤w�g��'o'�I�쩳�F�A�N�Хܬ��I��flag=1
					if(a[ cir[index][0]+1 ][ cir[index][1] ]=='x' || cir[index][0]==n-1 ){	 
						touch=1;
					}
					
					index++;
				}
			}
		}
		//printf("index=%d,touch=%d\n",index,touch);
		
		if(touch!=1){
			for(i=index-1;i>=0;i--){
				a[ cir[i][0]+1 ][ cir[i][1] ]='o';
				a[ cir[i][0]   ][ cir[i][1] ]='.';
				cir[i][0]=0,cir[i][1]=0;
			}
		}
	}
	/*printf("------------------------\n");
	for(i=0;i<n;i++){
		for(j=0;j<m;j++){
			printf("%c",a[i][j]);
		}
		printf("\n");
	}*/
	for(i=0;i<n;i++)
		for(j=0;j<m;j++)
			if(a[i][j]!='.')
				a[i][j]='x';
	/*printf("------------------------\n");
	for(i=0;i<n;i++){
		for(j=0;j<m;j++){
			printf("%c",a[i][j]);
		}
		printf("\n");
	}*/
			
	for(i=n-1;i>=0;i--){
		int clear=1;
		for(j=0;j<m;j++){
			if(a[i][j]=='.'){
				clear=0;
				break;
			}
		}
		if(clear==1){
			for(j=i;j>0;j--){
				for(k=0;k<m;k++){
					a[j][k]=a[j-1][k];
				}
			}
			for(j=0;j<m;j++){	//�O�o�̤W���@�泣�n��l�Ʀ�'.' 
				a[0][j]='.';
			}
			i++;			
		}
	}
	//printf("------------------------\n");
	for(i=0;i<n;i++){
		for(j=0;j<m;j++){
			printf("%c",a[i][j]);
		}
		printf("\n");
	}
	
	return 0;
}
