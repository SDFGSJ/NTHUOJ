#include <stdio.h>
#include <stdlib.h>
#include <string.h>
char p[10];
char s[500];
char **split_str_by_pattern(char* str, char* pattern, int* split_num);
void free_result(char **result, int split_num);
int main(){

    int i, split_num;
    char **result;
    scanf("%s",s);
    scanf("%s",p);
    result = split_str_by_pattern(s, p, &split_num);
    for(i=0; i<split_num; ++i){
        printf("%s\n",result[i]);
    }
    
    free_result(result, split_num);
    return 0;
}
int check_pattern(int start,int end,char *str,char *pattern)
{
	int i;
	for(i=start;i<end;i++){
		if(str[i]!=pattern[i-start]){
			return 0;
		}
	}
	return 1;
}
void create_string(int start,int end,char *str,int *split_num,char **res)
{
	int i;
	res[*split_num]=(char*)malloc( (end-start+1)*sizeof(char) );
	for(i=0;i<end-start;i++){
		res[*split_num][i]=str[start+i];
	}
	res[*split_num][end-start]='\0';
	(*split_num)++;
}
char **split_str_by_pattern(char* str, char* pat, int* split_num)
{
	int i=0;
	int str_len=strlen(str);
	int pat_len=strlen(pat);
	int start=0;
	*split_num=0;
	char **res=(char**)malloc(500*sizeof(char*));
	while(i<=str_len-pat_len)
	{
		int is_pat=check_pattern(i,i+pat_len,str,pat);
		if(is_pat){
			if(i-start>0)	//i-start==0就是遇到連續的pattern 
				create_string(start,i,str,split_num,res);
			i+=pat_len;
			start=i;
		}else{
			i++;
		}
	}
	if(start<str_len){
		create_string(start,str_len,str,split_num,res);
	}
	return res;
}
void free_result(char **result, int split_num)
{
	int i;
	for(i=0;i<split_num;i++){
		free(result[i]);
	}
	free(result);
}
