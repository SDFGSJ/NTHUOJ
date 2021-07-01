#include<stdio.h>
#include<string.h>

int t,la,lb,ans[505][505]={1};           
char a[505],b[505];
int main(void)
{
	int i,j;
    scanf("%s%s%d",a,b,&t);
	int la=strlen(a),lb=strlen(b);
    for(i=0;i<=la;i++){
    	for(j=1;j<=lb;j++){
    		if(i && (b[j-1]=='.' || a[i-1]==b[j-1]) )       // '.'或者是字母 
	            ans[i][j]=ans[i][j] | ans[i-1][j-1];
	        else if(b[j-1]=='*'){                           // '*' 
	            ans[i][j]=ans[i][j] | ans[i][j-2];          //擺0個前綴字母 
	            if(i && (b[j-2]=='.' || b[j-2]==a[i-1]) )   //擺連續個前綴字母
	                ans[i][j]=ans[i][j] | ans[i-1][j];
	        }
		}
	}
    while(t--)
	{
        scanf("%d%d",&la,&lb);
        if(ans[la][lb])
        	printf("True\n");
		else
			printf("False\n");		
    }
}
