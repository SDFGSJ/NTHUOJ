//bubble sort O(n^2) --> TLE
#include<stdio.h>
#include<string.h>
char input[200005][105];
char temp[105];
int main(void)
{
	int i,j,k;
	int idx=0;
	while(scanf("%s",&input[idx])!=EOF){
		idx++;
	}
	/*for(i=0;i<idx;i++){
		printf("%s\n",input[i]);
	}
	printf("idx=%d\n",idx);*/
	for(i=0;i<idx-1;i++){
		for(j=0;j<idx-1;j++){
			if(strcmp(input[j],input[j+1])>0){			
				strcpy(temp,input[j]);
				strcpy(input[j],input[j+1]);
				strcpy(input[j+1],temp);
			}
		}
	}
	for(i=0;i<idx;i++){
		printf("%s\n",input[i]);
	}
	return 0;
}
