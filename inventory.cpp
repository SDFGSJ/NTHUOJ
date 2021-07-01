#include<stdio.h>
#include<string.h>
typedef struct{
	char name[25];
	int cur_hp;
	int max_hp;
}pokemon;
pokemon input[110],temp;

void swap(int a,int b);

int main(void)
{
	int n;
	int i,j,k;
	scanf("%d",&n);
	for(i=0;i<n;i++){
		scanf("%s%d%d",&input[i].name,&input[i].cur_hp,&input[i].max_hp);
	}
	//first sort:hp is not full (i.e. current hp < max hp) goes to the front
	for(i=n-1;i>=0;i--){
		for(j=n-1;j>=1;j--){
			if(input[j].cur_hp<input[j].max_hp){
				swap(j,j-1);
			}
		}
	}
	/*printf("\n------------------\nfirst sort\nhp is not full (i.e. current hp < max hp) goes to the front\n");
	for(i=0;i<n;i++){
		printf("%s %d %d\n",input[i].name,input[i].cur_hp,input[i].max_hp);
	}*/
	//找出cur_hp==max_hp的邊界點
	int bound=n;
	for(i=0;i<n;i++){
		if(input[i].cur_hp==input[i].max_hp){
			bound=i;
			break;
		}
	}
	//printf("bound=%d\n",bound);
	//second sort:current hp is less goes to the front
	for(i=bound;i>=0;i--){
		for(j=bound-1;j>0;j--){
			if(input[j].cur_hp<input[j-1].cur_hp){
				swap(j,j-1);
			}
		}
	}
	//second sort(bound以後)
	for(i=n-1;i>=bound;i--){
		for(j=n-1;j>bound;j--){
			if(input[j].cur_hp<input[j-1].cur_hp){
				swap(j,j-1);
			}
		}
	}
	/*printf("\n------------------\nsecond sort\ncurrent hp is less goes to the front\n");
	for(i=0;i<n;i++){
		printf("%s %d %d\n",input[i].name,input[i].cur_hp,input[i].max_hp);
	}*/
	//third sort:max hp is less goes to the front
	for(i=bound;i>=0;i--){
		for(j=bound-1;j>=0;j--){
			if(input[j].cur_hp==input[j-1].cur_hp && input[j].max_hp<input[j-1].max_hp){
				swap(j,j-1);
			}
		}
	}
	/*printf("\n------------------\nthird sort\nmax hp is less goes to the front\n");*/
	for(i=0;i<n;i++){
		printf("%s %d %d\n",input[i].name,input[i].cur_hp,input[i].max_hp);
	}
	return 0;
}

void swap(int a,int b)
{
	temp=input[a];
	input[a]=input[b];
	input[b]=temp;
}
