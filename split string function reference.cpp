#include<string.h>
#include<stdlib.h>
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
	res[*split_num]=(char*)malloc( (end-start+1)*sizeof(char) );	//res的元素記住每一行字串的開頭位址 
	for(i=0;i<end-start;i++){
		res[*split_num][i]=str[start+i];	//塞字進去 
	}
	res[*split_num][end-start]='\0';	//記得在最後加一個'\0' 
	(*split_num)++;		//換下一行 
}
char **split_str_by_pattern(char* str, char* pat, int* split_num)
{
	int i=0;
	int str_len=strlen(str);
	int pat_len=strlen(pat);
	int start=0;	//記錄要塞入str[][]的字串的index
	*split_num=0;
	char **res=(char**)malloc(500*sizeof(char*));	//記得先分配空間給res 
	while(i<=str_len-pat_len)
	{
		int is_pat=check_pattern(i,i+pat_len,str,pat);
		if(is_pat){		//如果有對到 
			if(i-start!=0)	//i-start==0就是遇到連續的pattern(也可以i-start>0)，沒有這行會吃PE 
				create_string(start,i,str,split_num,res);
			i+=pat_len;		//將目前的位置往後移pat_len 
			start=i;	//start將記住下一個字串第一個的index 
		}else{
			i++;	//如果沒對到就直接跑下一個字 
		}
	}
	if(start<str_len){		//將結尾剩餘的字串利用res指標加到str[][]裡面
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
