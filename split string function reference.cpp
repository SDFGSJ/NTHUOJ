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
	res[*split_num]=(char*)malloc( (end-start+1)*sizeof(char) );	//res�������O��C�@��r�ꪺ�}�Y��} 
	for(i=0;i<end-start;i++){
		res[*split_num][i]=str[start+i];	//��r�i�h 
	}
	res[*split_num][end-start]='\0';	//�O�o�b�̫�[�@��'\0' 
	(*split_num)++;		//���U�@�� 
}
char **split_str_by_pattern(char* str, char* pat, int* split_num)
{
	int i=0;
	int str_len=strlen(str);
	int pat_len=strlen(pat);
	int start=0;	//�O���n��Jstr[][]���r�ꪺindex
	*split_num=0;
	char **res=(char**)malloc(500*sizeof(char*));	//�O�o�����t�Ŷ���res 
	while(i<=str_len-pat_len)
	{
		int is_pat=check_pattern(i,i+pat_len,str,pat);
		if(is_pat){		//�p�G����� 
			if(i-start!=0)	//i-start==0�N�O�J��s��pattern(�]�i�Hi-start>0)�A�S���o��|�YPE 
				create_string(start,i,str,split_num,res);
			i+=pat_len;		//�N�ثe����m���Ჾpat_len 
			start=i;	//start�N�O��U�@�Ӧr��Ĥ@�Ӫ�index 
		}else{
			i++;	//�p�G�S���N�����]�U�@�Ӧr 
		}
	}
	if(start<str_len){		//�N�����Ѿl���r��Q��res���Х[��str[][]�̭�
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
