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
		
		//������֪��r����פ���p 
		int lenA=strlen(a),lenB=strlen(b),L;
		if(lenA>lenB)
			L=lenB;
		else
			L=lenA;
		
				
		int match_len=0;//��勵�T���r��̤j����		
		for(j=1;j<=L;j++){
			int good=1;
			for(k=0;k<j;k++){
				if(a[ (lenA-j) + k ]!=b[k]){	//�qa���^�ƪ���j�Ӧr���}�l�A�v����b���C�@�Ӧr����� 
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
