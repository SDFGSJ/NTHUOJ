#include<stdio.h>
#include<string.h>
int main(void)
{	
	int i,j,k;
		
	char a[1010],b[1010];
	
	
	int t;
	scanf("%d",&t);
	
	for(i=0;i<t;i++){	
		scanf("%s%s",a,b);
		
		//先比較誰的字串長度比較小 
		int lenA=strlen(a),lenB=strlen(b),L;
		if(lenA>lenB)
			L=lenB;
		else
			L=lenA;
		
				
		int match_len=0;//比對正確的字串最大長度		
		for(j=1;j<=L;j++){
			int good=1;
			for(k=0;k<j;k++){
				if(a[ (lenA-j) + k ]!=b[k]){	//從a往回數的第j個字元開始，逐漸跟b的每一個字元比較 
					good=0;
					break;
				}
			}
			if(good)	match_len=j;
		}
		
		
		for(j=0;j<lenA-match_len;j++)
			printf("%c",a[j]);		
		for(j=0;j<lenB;j++)
			printf("%c",b[j]);		
		printf("\n");
				
	}
	return 0;
}
