#include<stdio.h>
int main(void)
{
	char map[15][15]={'\0'};
	int check[10]={0};
	int i,j,k,l,m;
	int flag1=0,flag2=0;
	
	for(i=0;i<13;i++)//可以用%4判斷要不要存到另一個陣列裡面(如果要的話記得額外設兩個index變數a,b)
		scanf("%s",&map[i]);				
			
	//先判斷是question還是solution 
	for(i=0;i<13;i++){
		for(j=0;j<13;j++){
			if(map[i][j]=='x'){
				flag1=1;
				break;
			}
		}
		if(flag1)	break;				
	}
	
	if(flag1){
		printf("question, ");
	}else{
		printf("solution, ");
	}
	
	//再判斷有沒有valid
	for(i=1;i<13;i+=4){		//row
		flag2=0;
		for(k=0;k<10;k++){
			check[k]=0;
		}
		/*printf("check[]=");
		for(int z=0;z<10;z++)	printf("%d",check[z]);*/
		for(j=1;j<13;j+=4){//這裡其實應該要判斷那格是不是'x' 
			check[ map[i][j]-'0' ]++;
			check[ map[i][j+1]-'0' ]++;
			check[ map[i][j+2]-'0' ]++;
		}
		/*printf("check[]=");
		for(int z=0;z<10;z++)	printf("%d",check[z]);
		printf("\n");*/
		for(l=1;l<10;l++){
			if(check[l]>1){
				flag2=1;
				break;
			}
		}
		if(flag2)	break;
		/*if(flag2){
			printf("invalid");
			break;
		}else{
			printf("valid");
			break;
		}*/		
	}
	
	for(i=1;i<13;i+=4){		//column
		flag2=0;
		for(k=0;k<10;k++){
			check[k]=0;
		}
		/*printf("check[]=");
		for(int z=0;z<10;z++)	printf("%d",check[z]);*/
		for(j=1;j<13;j+=4){//這裡其實應該要判斷那格是不是'x' 
			check[ map[j][i]-'0' ]++;
			check[ map[j+1][i]-'0' ]++;
			check[ map[j+2][i]-'0' ]++;
		}
		/*printf("check[]=");
		for(int z=0;z<10;z++)	printf("%d",check[z]);
		printf("\n");*/
		for(l=1;l<10;l++){
			if(check[l]>1){
				flag2=1;
				break;
			}
		}
		if(flag2)	break;
		/*if(flag2){
			printf("invalid");
			break;
		}else{
			printf("valid");
			break;
		}*/		
	}
	
	for(i=1;i<13;i+=4){		//block
		flag2=0;
		for(j=1;j<13;j+=4){
			for(m=0;m<10;m++){
				check[m]=0;
			}
			/*printf("check[]=");
			for(int z=0;z<10;z++)	printf("%d",check[z]);*/
			for(k=i;k<i+3;k++){
				for(l=j;l<j+3;l++){//這裡其實應該要判斷那格是不是'x' 
					check[map[k][l]-'0']++;
				}
			}
			/*printf("check[]=");
			for(int z=0;z<10;z++)	printf("%d",check[z]);
			printf("\n");*/
			for(int n=1;n<10;n++){
				if(check[n]>1){
					flag2=1;
					break;
				}
			}
			if(flag2)	break;
		}
		
		if(flag2)	break;	
	}
	if(flag2){
		printf("invalid\n");		
	}else{
		printf("valid\n");
	}
	return 0;
}
