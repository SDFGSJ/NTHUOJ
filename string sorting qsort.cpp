#include<stdio.h>
#include<string.h>
#include<stdlib.h>
char input[200005][105];
int cmp(const void *,const void *);
int main(void)
{
	int idx=0;
	int i;
	while(scanf("%s",&input[idx])!=EOF){
		idx++;
	}
	qsort(input,idx,sizeof(input[0]),cmp);
	for(i=0;i<idx;i++){
		printf("%s\n",input[i]);
	}
	return 0;
}
int cmp(const void *a,const void *b)
{
	const char *stra=(const char*)a;
	const char *strb=(const char*)b;
	return strcmp(stra,strb);
}
