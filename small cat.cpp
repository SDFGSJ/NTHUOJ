#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct{
	char name[40];
	int occu;
	int age;
}cat;
int n,food;
cat input[10005];
void convert(int,char);
int cmp(const void*,const void*);
int main(void)
{
	int i;
	while(scanf("%d%d",&n,&food)!=EOF)
	{
		char temp[40];
		for(i=0;i<n;i++)
		{
			scanf("%s%s%d",input[i].name,temp,&input[i].age);
			convert(i,temp[0]);
		}
		qsort(input,n,sizeof(cat),cmp);
		for(i=0;i<n && i<food;i++){
			printf("%s\n",input[i].name);
		}
	}
	return 0;
}
void convert(int i,char ch)
{
	switch(ch){
		case 'e':
			input[i].occu=0;
			break;
		case 'k':
			input[i].occu=1;
			break;
		case 'a':
			input[i].occu=2;
			break;
	}
}
int cmp(const void *a,const void *b)
{
	const cat c1=*(cat*)a;
	const cat c2=*(cat*)b;
	
	if(c1.occu > c2.occu)
		return 1;
	else if(c1.occu < c2.occu)
		return -1;
	else{
		if(c1.occu==2){
			if(c1.age > c2.age)
				return 1;
			else if(c1.age < c2.age)
				return -1;
			return strcmp(c1.name,c2.name);
		}else{
			if(c1.age > c2.age)
				return -1;
			else if(c1.age < c2.age)
				return 1;
			else
				return strcmp(c1.name,c2.name);
		}
	}
}
