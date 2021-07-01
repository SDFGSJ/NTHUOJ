#include<stdio.h>
int seq[200000+10]={0};//記錄數字 
int request[100000+10]={0};//記錄request 
int check[200000+10]={0};//記錄request中的數字有沒有出現過
int main(void)
{
	//freopen("output.txt","w",stdout);
	
	//n numbers from 1 to n
	//m requests
	int n,m;
	scanf("%d%d",&n,&m);
	
	for(int i=0;i<m;i++)
		scanf("%d",&request[i]);
			
	//build a sequence
	for(int i=1;i<=n;i++)
		seq[i-1]=i;
	
		
	
	//先把request的數字解決掉 
	for(int i=m-1;i>=0;i--){
		if(check[ request[i] ]!=-1){//只要這個request還沒出現過 
			printf("%d\n",request[i]);
			check[ request[i] ]=-1;//該request標記為出現過 
			seq[ request[i]-1 ]=-1;//該數字標記為出現過		
		}
	}
	
	
	
	//print out
	for(int i=0;i<n;i++){
		if(seq[i]!=-1){			
			printf("%d\n",seq[i]);						
		}		
	}
	
	
	/*printf("\ncheck[]=");
	for(int i=0;i<20;i++){
		printf("%d ",check[i]);
	}
	printf("\n");*/
	
	
	/*printf("seq[]=");
	for(int i=0;i<n;i++){
		printf("%d ",seq[i]);
	}
	printf("\n");*/
	
	
	return 0;
}
