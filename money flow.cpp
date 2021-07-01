#include<stdio.h>
double rate[505][505]={0.0};//記錄比率  
double bank[505]={0.0};//各銀行的錢
double temp[505]={0.0};//(錢*比率)算完後暫存到這邊 
int main(void)
{	
	//總共num間銀行,過了day天 
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
		//錢*比率	
		for(i=0;i<num;i++)
			for(j=0;j<num;j++)
				temp[i]+=bank[j]*rate[j][i];	//每次都加總，這樣就不用多寫一個迴圈 
					
		for(i=0;i<num;i++){
			bank[i]=temp[i];	//將temp[i]的結果存到bank[i]裡面 
			temp[i]=0;	//temp[i]順便歸0，這樣就可以省一個迴圈 
			if(bank[i]<10){		//如果該銀行破產了 
				for(j=0;j<num;j++){
					if(i!=j){
						rate[j][j]+=rate[j][i];	//把那個破產銀行的比率歸給自己 
						
						rate[i][j]=0,rate[j][i]=0;	//大十字歸0 						
					}else{
						rate[i][i]=1.0; //該銀行不用進出任何錢，自己給自己錢就好 
					}
					
				}
			}
		}			
	}
	
	for(i=0;i<num;i++)
		printf("%.1f\n",bank[i]);
						
	return 0;
}
