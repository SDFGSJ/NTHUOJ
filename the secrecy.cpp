#include<stdio.h>
#include<string.h>
int fre[5005];	//�O���W�v 
char pat[5005];
char input[5005];
char str[5005][5005];	//�O���r�굪�� 
int kind=0;		//�O������ 
int check(char *input,char*p);
void sort();
//void display();
int main(void)
{
	int n;
	int i,j;
	scanf("%d%s",&n,pat);
	for(i=0;i<n;i++){
		scanf("%s",input);
		int same=0;
		if(check(input,pat)==0){	//�p�G���A���@�˴N���U�@�Ӧr�� 
			continue;
		}
		for(j=0;j<kind;j++){	//�qstr[][]����0��}�l�ˬd 
			if(strcmp(str[j],input)==0){	//�p�G�o����input�r��H�e���X�{�L�ӥB�w�g�Q�s�bstr[j][]�̤F 
				same=1;
				break;	//���F�O�d�{�b��j 
			}
		}
		if(same){
			fre[j]++;	//�Ӧ檺�W�v�[1 
		}else{		//�p�G�o��input�O�s���r�� 
			strcpy(str[kind],input);	//�N�o�ӷs�r��[��str[][]�̭� 
			fre[kind]=1;	//�N���W�v�]��1 
			kind++;		//�����[1 
		}
	}
	sort();		//�N�W�v�Ѥj��p�ƦC 
	//display();
	printf("%d\n",kind);
	for(i=0;i<kind;i++){
		printf("%s %d\n",str[i],fre[i]);
	}
	return 0;
}
int check(char *input,char *p)
{
	int i;
	char alph1[26]={'\0'};
	char alph2[26]={'\0'};
	
	if(strlen(input)!=strlen(p)){	//�p�G���פ��@�ˡA���A�@�w���@�� 
		return 0;
	}else{
		for(i=0;i<strlen(p);i++){
			int idx1=input[i]-'a';
			int idx2=p[i]-'a';
			if(alph1[idx1]=='\0' && alph2[idx2]=='\0'){		//�p�G����O�Ū��ܡA�N��r�s�i�h 
				alph1[idx1]=p[i];
				alph2[idx2]=input[i];
			}else{
				if(alph1[idx1]==p[i] && alph2[idx2]==input[i]){		//�p�G�Ӯ�w�g���r�ӥB��n��J���r�@�ˡA�N����scanf�U�@�Ӧr 
					continue;
				}else{
					return 0;	//�o��collision 
				}
			}
		}
	}
	return 1;
	/*printf("alph1[]=");
	for(i=0;i<26;i++){
		printf("%c",alph1[i]);
	}
	printf("\nalph2[]=");
	for(i=0;i<26;i++){
		printf("%c",alph2[i]);
	}
	printf("\n-----------------------\n");*/
}
void sort()
{
	int i,j;
	for(i=0;i<kind;i++){
		for(j=0;j<kind-1-i;j++){
			int must_change=0;
			if(fre[j]<fre[j+1]){
				must_change=1;
			}else if(fre[j]>fre[j+1]){
				must_change=0;
			}else{	//fre[i]==fre[j+1]�A�N��X�{�W�v�ۦP���n��|�W�v 
				if(strcmp(str[j],str[j+1])>0){		//�p�Gstr[j]���r��acsii����j�N�n�洫 
					must_change=1;
				}else{
					must_change=0;
				}
			}
			if(must_change){
				char change[5010];
				strcpy(change,str[j]);
				strcpy(str[j],str[j+1]);
				strcpy(str[j+1],change);
				
				int change_int;
				change_int=fre[j];
				fre[j]=fre[j+1];
				fre[j+1]=change_int;
			}
		}
	}
}
/*void display()
{
	int i,j;
	printf("fre[]=");
	for(i=0;i<10;i++){
		printf("%d,",fre[i]);
	}
	printf("\npat[]=%s\n",pat);
	printf("str[][]=\n");
	for(i=0;i<10;i++){
		printf("%s\n",str[i]);
	}
	printf("input=%s\n",input);
	printf("kind=%d\n",kind);	
}*/
