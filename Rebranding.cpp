#include<stdio.h>
char name[200010];
char alpha[26];
int main(void)
{
	int i,j;
	int len,people;
	char x,y;
	scanf("%d%d",&len,&people);
	scanf("%s",name);
	
	for(i=0;i<26;i++){	//�Nalpha�}�C��l�� 
		alpha[i]='a'+i;
	}
	//printf("%s\n",alpha);
	
	for(i=0;i<people;i++){
		getchar();	//�`�N���� 
		scanf("%c %c",&x,&y);	//�`�N�ť� 
		if(x==y)	continue;	//�p�G��Ӧr���۵��N�����]�U�@�� 
		for(j=0;j<26;j++){
			if(alpha[j]==x){
				alpha[j]=y;
			}else if(alpha[j]==y){
				alpha[j]=x;
			}
		}
	}
	
	for(i=0;i<len;i++){
		printf("%c",alpha[name[i]-'a']);
	}
	printf("\n");	
	return 0;
}
