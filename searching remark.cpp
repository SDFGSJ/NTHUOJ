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
		ptr=strtok(content,d);	//�����@�q 
		while(ptr!=NULL)	//�u�n���X�Ӫ����G���ONULL 
		{
			/*-1�O�]��fgets�|�Y��'\n'*/
			if(strlen(ptr)!=strlen(key)-1){	//�p�G���פ��@�˴N�@�w���X�A�������U�@�q 
				ptr=strtok(NULL,d);
				continue;
			}
			for(i=0;i<strlen(key)-1;i++){	//�u�n�j�p�g���X�N���X�j�� 
				if(key[i]!=ptr[i] && key[i]!=ptr[i]-32 && key[i]!=ptr[i]+32)
					break;
			}
			if(i==strlen(key)-1){	//�p�G�j�馳�]��̫�N�N��ڭ̦���쵪�� 
				count++;
			}
			ptr=strtok(NULL,d);		//�~����U�@�q��r 
		}
	}
	printf("%d\n",count);
	return 0;
}
