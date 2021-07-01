#include <stdio.h>
//#include "function.h"

#define maxn 1000

char input[1000010];

int main() {
	int i,j;
    int sum = 0;
	int a[maxn];
	int *ptr[maxn];

	for (i = 0; i < maxn; i++) {
		a[i] = 0;		//把a[i]都歸0 
		ptr[i] = &a[i];	//讓ptr[i]記住a[i]的位址 
	}

	scanf("%s", input);
	int n = solver(ptr, &sum, input);	//回傳數字個數n 
	printf("%d", a[0]);
	for (i = 1; i < n; i++)
		printf(" %d", a[i]);
	printf("\n%d\n", sum);
	return 0;
}
#include<string.h>
int solver(int **ptr, int *sum, char *s)
{
	int i;
	int count=0,num=0,ok=0,sign=1;
	int len=strlen(s);
	
	for(i=0;i<=len;i++){
		if('0'<=s[i] && s[i]<='9'){
			num=num*10+s[i]-'0';
			ok=1;
		}else{
			if(ok){
				*ptr[count]=sign*num;
				*sum+=sign*num;
				count++;
			}
			if(s[i]=='-'){
				sign=-1;			
			}else{
				sign=1;		
			}
			ok=0;
			num=0;
		}
	}
	return count;
}
