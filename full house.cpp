#include<stdio.h>
int main(void)
{
	int n;
	int i,j;
	char card[5][3];
	
	scanf("%d",&n);
	while(n--)
	{
		int flag_2=0,flag_3=0;
		
		int check[14]={0};
		
		for(i=1;i<14;i++)
			check[i]=0;
		
		
		for(i=0;i<5;i++){
			scanf("%s",card[i]);
			if(card[i][0]=='A')
				check[1]++;
			else if(card[i][0]=='1')
				check[10]++;
			else if(card[i][0]=='J')
				check[11]++;
			else if(card[i][0]=='Q')
				check[12]++;
			else if(card[i][0]=='K')
				check[13]++;
			else
				check[ card[i][0]-'0' ]++;
		}		
			
		for(i=1;i<14;i++){
			if(check[i]==2){
				flag_2=1;
			}else if(check[i]==3){
				flag_3=1;
			}
		}
		
		if(flag_2&&flag_3)
			printf("YES\n");
		else
			printf("NO\n");
		
	}
	return 0;
}
