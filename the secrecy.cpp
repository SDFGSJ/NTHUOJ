#include<stdio.h>
#include<string.h>
int fre[5005];	//記錄頻率 
char pat[5005];
char input[5005];
char str[5005][5005];	//記錄字串答案 
int kind=0;		//記錄種類 
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
		if(check(input,pat)==0){	//如果型態不一樣就換下一個字串 
			continue;
		}
		for(j=0;j<kind;j++){	//從str[][]的第0行開始檢查 
			if(strcmp(str[j],input)==0){	//如果這次的input字串以前有出現過而且已經被存在str[j][]裡了 
				same=1;
				break;	//為了保留現在的j 
			}
		}
		if(same){
			fre[j]++;	//該行的頻率加1 
		}else{		//如果這個input是新的字串 
			strcpy(str[kind],input);	//將這個新字串加到str[][]裡面 
			fre[kind]=1;	//將該頻率設為1 
			kind++;		//種類加1 
		}
	}
	sort();		//將頻率由大到小排列 
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
	
	if(strlen(input)!=strlen(p)){	//如果長度不一樣，型態一定不一樣 
		return 0;
	}else{
		for(i=0;i<strlen(p);i++){
			int idx1=input[i]-'a';
			int idx2=p[i]-'a';
			if(alph1[idx1]=='\0' && alph2[idx2]=='\0'){		//如果那格是空的話，就把字存進去 
				alph1[idx1]=p[i];
				alph2[idx2]=input[i];
			}else{
				if(alph1[idx1]==p[i] && alph2[idx2]==input[i]){		//如果該格已經有字而且跟要塞入的字一樣，就直接scanf下一個字 
					continue;
				}else{
					return 0;	//發生collision 
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
			}else{	//fre[i]==fre[j+1]，代表出現頻率相同不要交會頻率 
				if(strcmp(str[j],str[j+1])>0){		//如果str[j]的字母acsii比較大就要交換 
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
