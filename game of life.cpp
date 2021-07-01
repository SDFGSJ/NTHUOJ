#include<stdio.h>
#include<string.h>
#define REP(i,j,k) for(int i=j;i<k;i++)
int a[505][505],b[505][505];
int main(void){
	int n,m,t,count;
	int i,j,k,l;
    scanf("%d%d%d",&n,&m,&t);
    
    for(i=1;i<=n;i++){
    	for(j=1;j<=m;j++){
    		scanf("%d",&a[i][j]);
		}
	}

    while(t--){
    	for(i=1;i<=n;i++){
    		for(j=1;j<=m;j++){
    			count=0;
    			if(a[i][j]==1){  				
    				for(k=i-1;k<=i+1;k++){
    					for(l=j-1;l<=j+1;l++){
    						if(k==i&&l==j){
    							continue;
							}
    						if(a[k][l]==1){
    							count++;
							}							
						}						
					}
    																						
					if(count==2||count==3)
						b[i][j]=1;
											
				}else{
					for(k=i-1;k<=i+1;k++)
    					for(l=j-1;l<=j+1;l++)
    						if(a[k][l]==1)
    							count++;
    				
    				if(count==3)
    					b[i][j]=1;
					
				}
			}
		}
     
        for(i=1;i<=n;i++){
        	for(j=1;j<=m;j++){
        		a[i][j]=b[i][j];
        		b[i][j]=0;
			}
		}
    }
    
    
    for(i=1;i<=n;i++){
        for(j=1;j<=m;j++){
        	if(j!=m)
            	printf("%d ",a[i][j]);
			else
				printf("%d\n",a[i][j]);        
        }
    }
    
    
    return 0;
}
