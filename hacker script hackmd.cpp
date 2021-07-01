#include<stdio.h>
#include<string.h>

char system[25], protect[25];
int out[25];

int lenA,lenB;
int haveAns=0;

void find(int indexA,int indexB){
    int i,j;
    if(indexA==lenA && indexB==lenB){	//如果已經到字串的結尾時 
        int printed=0;
        for(i=j=0;i<lenB;i++){
            if(out[j] == -1){
                j++;
                continue;
            }
            if(printed) 
				printf(" ");
            while(j<lenA && out[j]==i){
                printf("%c",system[j]);
                printed=1;
                j++;
            }
        }
        printf("\n");
        haveAns=1;
    }else if(indexA<lenA && indexB<=lenB){
        if(protect[indexB]=='#') {
            out[indexA]=indexB;
            find(indexA+1,indexB+1);
            find(indexA+1,indexB);
        }else{
            out[indexA]=-1;
            if(system[indexA]==protect[indexB])
                find(indexA+1,indexB+1);
        }
    }
}

int main(void){
    scanf("%s%s",system,protect);
    lenA=strlen(system);
    lenB=strlen(protect);
    
    find(0,0);
    
    if(!haveAns){
        printf("What the hack!?\n");
    }
    
    /*printf("\nout[]=");
    for(int i=0;i<25;i++){
    	printf("%2d",out[i]);
	}*/
    return 0;
}
