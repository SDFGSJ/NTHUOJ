#include<stdio.h>
#include<string.h>
char input[20],ans[20];
int len,notFirst;

void bubble_sort(int);
void f(int,int);

int main(void)
{
	scanf("%s",input);
	len=strlen(input);
	bubble_sort(len);	//���復��soring
	
	//printf("%s\n",input);
	
	f(0,0);
	printf("\n");
	return 0;
}
void bubble_sort(int n)
{
	int i,j;
	char temp;
	for(i=0;i<n-1;i++){
		for(j=0;j<n-i-1;j++){
			if(input[j]>input[j+1]){
				temp=input[j];
				input[j]=input[j+1];
				input[j+1]=temp;
			}
		}
	}
}
void f(int level,int count)
{
	int i;
	if(level<len){
		//choose
		ans[count]=input[level];	//��ثeinput���r����ians
		if(count>=3){		//�p�G�w�g��4�Ӧr���N�i�H�}�l�L�F 
			if(notFirst)	//�p�G�����O�Ĥ@��
				printf(", ");			
			for(i=0;i<=count;i++)
				printf("%c",ans[i]);
			notFirst=1;		//���A�]���O�Ĥ@��
		}
		f(level+1,count+1);
		
		//not choose
		f(level+1,count);
	}
}
