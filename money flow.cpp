#include<stdio.h>
double rate[505][505]={0.0};//�O����v  
double bank[505]={0.0};//�U�Ȧ檺��
double temp[505]={0.0};//(��*��v)�⧹��Ȧs��o�� 
int main(void)
{	
	//�`�@num���Ȧ�,�L�Fday�� 
	int num,day;
	
	int i,j,k;
//---------------------------------------------
	scanf("%d%d",&num,&day);
	
	for(i=0;i<num;i++)
		scanf("%lf",&bank[i]);
	
	for(i=0;i<num;i++)
		for(j=0;j<num;j++)
			scanf("%lf",&rate[i][j]);
		
//---------------------------------------------	
	while(day--){					
		//��*��v	
		for(i=0;i<num;i++)
			for(j=0;j<num;j++)
				temp[i]+=bank[j]*rate[j][i];	//�C�����[�`�A�o�˴N���Φh�g�@�Ӱj�� 
					
		for(i=0;i<num;i++){
			bank[i]=temp[i];	//�Ntemp[i]�����G�s��bank[i]�̭� 
			temp[i]=0;	//temp[i]���K�k0�A�o�˴N�i�H�٤@�Ӱj�� 
			if(bank[i]<10){		//�p�G�ӻȦ�}���F 
				for(j=0;j<num;j++){
					if(i!=j){
						rate[j][j]+=rate[j][i];	//�⨺�ӯ}���Ȧ檺��v�k���ۤv 
						
						rate[i][j]=0,rate[j][i]=0;	//�j�Q�r�k0 						
					}else{
						rate[i][i]=1.0; //�ӻȦ椣�ζi�X������A�ۤv���ۤv���N�n 
					}
					
				}
			}
		}			
	}
	
	for(i=0;i<num;i++)
		printf("%.1f\n",bank[i]);
						
	return 0;
}
