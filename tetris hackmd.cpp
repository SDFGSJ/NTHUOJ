#include<stdio.h>
char a[50][50];
int main(void)
{
	int n,m,touch=0,clear=0;
	int i,j,k;
	scanf("%d%d",&n,&m);
	
	for(i=0;i<n;i++){
		scanf("%s",a[i]);
	}
	
	while(1)
	{
		//�ˬd���S��touch 
		for(i=0;i<n;i++){
			for(j=0;j<m;j++){
				if(a[i][j]=='o'){
					if(i==n-1 || a[i+1][j]=='x'){	//�u�n'o'�I�쩳�άO'o'�U���O'x'�A�htouch�令1��ܸI�� 
						touch=1;
					}
				}
			}
		}
		
		if(touch)	break;	//�p�G�I��F�A�N�����j��A���ΰ��U����'o'�U�� 
		
		for(i=n-1;i>=0;i--){	//�q���U��'o'�}�l�� 
			for(j=0;j<m;j++){
				if(a[i][j]=='o'){
					a[i+1][j]='o';
					a[i][j]='.';
				}
			}
		}
	}
	
	for(i=n-1;i>=0;i--){
		clear=1;	//�����]�C�@�泣�i�H���� 
		for(j=0;j<m;j++){
			if(a[i][j]=='.'){	//�p�G����F'.'�A�N�N��o�椣������Aclear�]��0 
				clear=0;
			}else if(a[i][j]=='o'){		//�p�G�O'o'�N���K�令'x' 
				a[i][j]='x';
			}
		}
		if(clear){
			for(j=i;j>=1;j--){
				for(k=0;k<m;k++){
					a[j][k]=a[j-1][k];
				}
			}
			for(j=0;j<m;j++){	//�Ĥ@��@����s��'.' 
				a[0][j]='.';
			}
			i++;	//���F���C�@���ˬd���q�̫�@��}�l 
		}
	}
	
	for(i=0;i<n;i++){
		for(j=0;j<m;j++){
			printf("%c",a[i][j]);
		}
		printf("\n");
	}
	return 0;
}
