#include<stdio.h>
#include<string.h>
#include<stdlib.h>
typedef struct{
	char name[35];
	int occu;
	int age;
}cat;

cat input[10005];

void convert(int,char);
int cmp(const void *,const void *);

int main(void)
{
	int n,m;
	int i,j;
	while(scanf("%d%d",&n,&m)!=EOF)
	{
		char temp[15];
		for(i=0;i<n;i++){
			scanf("%s%s%d",input[i].name,temp,&input[i].age);
			convert(i,temp[0]);
		}
		qsort(input,n,sizeof(cat),cmp);
		/*要注意貓少食物多的情形*/
		for(i=0;i<n && i<m;i++){
			printf("%s\n",input[i].name);
		}
	}
	return 0;
}
void convert(int idx,char ch)
{
	switch(ch){
		case 'e':
			input[idx].occu=1;
			break;
		case 'n':
			input[idx].occu=2;
			break;
		case 'k':
			input[idx].occu=3;
			break;
		case 'w':
			input[idx].occu=4;
			break;
		case 'a':
			input[idx].occu=5;
			break;
		case 'm':
			input[idx].occu=6;
			break;
		case 'd':
			input[idx].occu=7;
			break;
		case 'l':
			input[idx].occu=8;
			break;
	}
}
int cmp(const void *a,const void *b)
{
	const cat cat_a = *(const cat*)a;
	const cat cat_b = *(const cat*)b;
	if(cat_a.occu > cat_b.occu){
		return 1;
	}else if(cat_a.occu < cat_b.occu){
		return -1;
	}else{
		if(cat_a.occu==5){
			if(cat_a.age > cat_b.age){
				return 1;
			}else if(cat_a.age < cat_b.age){
				return -1;
			}else{
				return strcmp(cat_a.name,cat_b.name);
			}
		}else{
			if(cat_a.age > cat_b.age){
				return -1;
			}else if(cat_a.age < cat_b.age){
				return 1;
			}else{
				return strcmp(cat_a.name,cat_b.name);
			}
		}
	}
}
