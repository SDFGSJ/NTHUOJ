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
	
	for(i=0;i<26;i++){	//將alpha陣列初始化 
		alpha[i]='a'+i;
	}
	//printf("%s\n",alpha);
	
	for(i=0;i<people;i++){
		getchar();	//注意換行 
		scanf("%c %c",&x,&y);	//注意空白 
		if(x==y)	continue;	//如果兩個字母相等就直接跑下一圈 
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
