#include<stdio.h>
#include<string.h>
char key[25];
char content[510];
char d[15] = {' ','\n','-','/',':','(',')','[',']',',','.'};
int main(void)
{
	int i,count=0;
	char *ptr;
	scanf("%s",key);
	while(fgets(content,510,stdin)!=0)
	{
		ptr=strtok(content,d);	//先切一段 
		while(ptr!=NULL)	//只要切出來的結果不是NULL 
		{
			/*-1是因為fgets會吃到'\n'*/
			if(strlen(ptr)!=strlen(key)-1){	//如果長度不一樣就一定不合，直接切下一段 
				ptr=strtok(NULL,d);
				continue;
			}
			for(i=0;i<strlen(key)-1;i++){	//只要大小寫不合就跳出迴圈 
				if(key[i]!=ptr[i] && key[i]!=ptr[i]-32 && key[i]!=ptr[i]+32)
					break;
			}
			if(i==strlen(key)-1){	//如果迴圈有跑到最後就代表我們有找到答案 
				count++;
			}
			ptr=strtok(NULL,d);		//繼續切下一段文字 
		}
	}
	printf("%d\n",count);
	return 0;
}
