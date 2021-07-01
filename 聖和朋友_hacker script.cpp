#include <stdio.h>
char system[21];
char protect[21];
char ans[20][21];
int haveAns=0;

void run(char *S,char *P,int ansnow){
    if(*S=='\0' || *P=='\0'){	//終止條件，如果兩字串其中一個已經到終點了 
        if(*S==*P){		//如果兩字串都到終點了，就開始印 
            for(int i=0;i<ansnow;i++){
            	//printf("%s%c",ans[i]," \n"[i==ansnow-1]);
            	printf("%s",ans[i]);
            	if(i==ansnow-1){
            		printf("\n");
				}else{
					printf(" ");
				}
			}
            haveAns=1;		//表示有答案了
            return;
        }else{
        	return;
		}			
    }


    if(*P=='#'){
        for(int i=0;*(S+i)!='\0';i++){
            ans[ansnow][i]=*(S+i);		//將該字母存進ans[][]裡 
        	ans[ansnow][i+1]='\0';		//先在後面加一個結尾符號給它 
        	run(S+i+1,P+1,ansnow+1);
		}
    }else if(*S==*P){	//如果S,P現在的字母都一樣，就不用理它，兩個字串都往下一個字母前進 
    	run(S+1,P+1,ansnow);
	}
	
	return;
}

int main(void){
    scanf("%s",system);
    scanf("%s",protect);
    
    run(system,protect,0);
    
    if(haveAns==0)
    	printf("What the hack!?\n");
	
    return 0;
}
