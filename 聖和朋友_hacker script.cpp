#include <stdio.h>
char system[21];
char protect[21];
char ans[20][21];
int haveAns=0;

void run(char *S,char *P,int ansnow){
    if(*S=='\0' || *P=='\0'){	//�פ����A�p�G��r��䤤�@�Ӥw�g����I�F 
        if(*S==*P){		//�p�G��r�곣����I�F�A�N�}�l�L 
            for(int i=0;i<ansnow;i++){
            	//printf("%s%c",ans[i]," \n"[i==ansnow-1]);
            	printf("%s",ans[i]);
            	if(i==ansnow-1){
            		printf("\n");
				}else{
					printf(" ");
				}
			}
            haveAns=1;		//��ܦ����פF
            return;
        }else{
        	return;
		}			
    }


    if(*P=='#'){
        for(int i=0;*(S+i)!='\0';i++){
            ans[ansnow][i]=*(S+i);		//�N�Ӧr���s�ians[][]�� 
        	ans[ansnow][i+1]='\0';		//���b�᭱�[�@�ӵ����Ÿ����� 
        	run(S+i+1,P+1,ansnow+1);
		}
    }else if(*S==*P){	//�p�GS,P�{�b���r�����@�ˡA�N���βz���A��Ӧr�곣���U�@�Ӧr���e�i 
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
