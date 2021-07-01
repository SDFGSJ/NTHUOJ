#include<stdio.h>

char s[25],p[25];
int t;
int possibleways=0;

void run(char *s,char *p, int ansnow);

int main(void){
    scanf("%d", &t);
    while(t--){
        scanf("%s", s);
        scanf("%s", p);
        run(s,p,0);
        printf("%d\n", possibleways);
        possibleways = 0;
    }
    return 0;
}

 void run(char *s,char *p,int ansnow){
    if(*s == '\0' || *p == '\0'){
        if(*s == *p)
            possibleways++;
        return;
    }
    if(*p == '#'){
        for(int i=0;*(s+i)!='\0';i++){
            run(s+i+1,p+1,ansnow+1);
        }
    }
    else if(*p == '$'){
        for(int i=0;*(s+i)!='\0';i++){
            if(*(s+i) == *s)
				run(s+i+1,p+1,ansnow+1);
    		else 
				return;
        }
    }
    else if(*s == *p){
        run(s+1,p+1,ansnow);
    }
 }
