#include<stdio.h>
#include<string.h>
char input[20],ans[20];
int notFirst,len;

void bubble_sort(int);
void f(int,int);

int main(void){
    scanf("%s",input);
    len = strlen(input);   
    bubble_sort(len);
    //printf("%s\len",input);
    
    f(0,0);
    printf("\n");
    
    return 0;
}
void bubble_sort(int len)
{
	int i,j;
	char temp;
	for(i=0;i<len-1;i++){
		for(j=0;j<len-i-1;j++){
			if(input[j]>input[j+1]){
				temp=input[j];
				input[j]=input[j+1];
				input[j+1]=temp;
			}
		}
	}	
}
void f(int level,int count){
    if(level<len){   	
        //choose
        ans[count] = input[level];	
        if(count>=3){ 
            if(notFirst) 
				printf(", ");
            for(int i=0;i<=count;i++){
            	printf("%c",ans[i]);
			}
            notFirst=1;
        }
        f(level+1,count+1);
        
        //not choose
        f(level+1,count);
    }
}
