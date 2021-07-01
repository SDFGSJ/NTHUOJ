#include<stdio.h>
int main(void)
{	//n numbers,help them q times,left range l,right range r
	int n,q,l,r,index=0;
	int dish[500]={0},times[500]={0},minnum[500]={0};
	//loop variables
	int i,j,k;
	
	scanf("%d",&n);
	for(i=0;i<n;i++){
		scanf("%d",&dish[i]);
	}
	
	scanf("%d",&q);
	for(i=0;i<q;i++){
		index=0;//remember to set index=0 before each comparison
		scanf("%d%d",&l,&r);
		//initialize
		for(j=0;j<n;j++){
			times[j]=0;
			minnum[j]=0;
		}
		//comparing
		for(j=l-1;j<r;j++){
			for(k=l-1;k<r;k++){
				if(dish[j]==dish[k])
					times[j]++;			
			}
		}
		//record max appearing times
		int max=times[0];
		for(j=0;j<n;j++){
			if(times[j]>max)
				max=times[j];
		}
		//record min dish number
		for(j=0;j<n;j++){
			if(times[j]==max){
				minnum[index]=dish[j];
				index++;
			}
		}
		//check which is the smallest dish number
		int min=minnum[0];
		for(j=0;j<index;j++){
			if(min>minnum[j])
				min=minnum[j];		
		}
		//print the final answer
		printf("%d\n",min);	
	}
	
	return 0;
}
