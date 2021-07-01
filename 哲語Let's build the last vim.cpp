#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<stdbool.h>
#include<ctype.h>
#define max(a,b) (a>b?a:b)
#define min(a,b) (a<b?a:b)

int times;
int T;
char s[3000];

char *ptr[1001];
char tem[16000010];

int len[1010];
bool cont=0;
int cont_num;

bool mode;
int cursor;
int height;
int lens;
int re;

int main(){
    scanf("%d",&T);
    for(times=1;times<=T;times++){
        scanf("%s",s);
        cont=height=mode=cursor=0;
        re=1;
        for(int i=0;i<1010;i++){
            len[i]=0;
        }
        for(int i=0;i<=strlen(s);i++){
            if(s[i]==':' && s[i+1]=='w' && s[i+2]=='q')	break;
            if(mode==1){
                if(s[i]=='E' && s[i+1]=='S' && s[i+2]=='C'){
                    mode=0;
                    cursor=max(cursor-1,0);
                    i+=2;
                }else{
                    int tr=i;
                     while(s[tr]!='E' || s[tr+1]!='S' || s[tr+2]!='C'){
                        tr++;
                    }
                    int ch=tr-i;
                    memset(tem,'\0',sizeof(tem));
                    if(len[height]>0){
                        strcpy(tem,ptr[height]);
                        free(ptr[height]);
                    }
                    for(int j=len[height]-1;j>=cursor;j--){
                        tem[j+ch]=tem[j];
                    }
                    for(int j=0;j<ch;j++){
                        tem[cursor+j]=s[i+j];
                    }
                    cursor+=ch;
                    len[height]+=ch;
                    i=i+ch-1;
                    ptr[height]=(char*)malloc(sizeof(char)*(len[height]+1) );
                    //printf("%s\n",tem);
                    tem[len[height]]='\0';
                    strcpy(ptr[height],tem);
                }
                cont=0;
            }
            else if(mode==0){
                if(s[i]=='I'){
                    if(i>0 && isdigit(s[i-1]) && re>0&&s[i+1]!='E'){
                        //memset(tem,'\0',sizeof(tem));
                        int tr=i;
                        while(s[tr]!='E' || s[tr+1]!='S' || s[tr+2]!='C'){
                        	tr++;
                        }
                        int ch=tr-i-1;
                        for(int j=0;j<re;j++){
                            for(int ii=0;ii<ch;ii++)
                            	tem[j*ch+ii]=s[i+ii+1];
                        }
                        if(len[height]>0){
	                        for(int j=0;j<len[height];j++){
	                            tem[re*ch+j]=ptr[height][j];
	                        }
	                        free(ptr[height]);
                        }
                        len[height]=len[height]+re*ch;
                        ptr[height]=(char*)malloc(sizeof(char)*(len[height]+1) );
                        tem[len[height]]='\0';
                        strcpy(ptr[height],tem);
                        i+=ch;
                        cursor=ch*re;
                    }else{
                    	cursor=0;
                    }
                    mode=1;
                    re=1;
                    cont=0;
                }else if(s[i]=='i'){
                    if(i>0 && isdigit(s[i-1]) && re>0&&s[i+1]!='E'){
                        //memset(tem,'\0',sizeof(tem));
                    	int tr=i;
                        while(s[tr]!='E' || s[tr+1]!='S' || s[tr+2]!='C'){
                        	tr++;
                        }
                        int ch=tr-i-1;
                        int temc=0;
                        //printf("%d\n",len[height]);
                        if(len[height]>0){
                            for(temc=0;temc<cursor;temc++){
                                tem[temc]=ptr[height][temc];
                            }
                        }
                        for(int j=0;j<re;j++){
                            for(int ii=0;ii<ch;ii++){
                                tem[temc]=s[i+1+ii];
                                temc++;
                            }
                        }
                        if(len[height]>0){
	                        for(int j=cursor;j<len[height];j++){
	                            tem[temc]=ptr[height][j];
	                            temc++;
	                        }
	                        free(ptr[height]);
                        }
                        len[height]=len[height]+re*ch;
                        tem[len[height]]='\0';
                        ptr[height]=(char*)malloc(sizeof(char)*(len[height]+1 ));
                        strcpy(ptr[height],tem);
                        i+=ch;
                        cursor=cursor+ch*re;
                    }else{
                    	mode=1;
                    }
                    mode=1;
                    re=1;
                    cont=0;
                }
                else if(s[i]=='A'){
                    if(i>0 && isdigit(s[i-1]) && re>0&&s[i+1]!='E'){
                            //memset(tem,'\0',sizeof(tem));
                        int tr=i;
                        while(s[tr]!='E' || s[tr+1]!='S' || s[tr+2]!='C'){
                        	tr++;
                        }
                        int ch=tr-i-1;
                        if(len[height]>0){
	                        strcpy(tem,ptr[height]);
	                        free(ptr[height]);
                        }
                        for(int j=0;j<ch*re;j++){
                            tem[len[height]+j]=s[j%ch+i+1];
                        }
                        len[height]=len[height]+re*ch;
                        tem[len[height]]='\0';
                        i+=ch;
                        ptr[height]=(char*)malloc(sizeof(char)*(len[height]+1) );
                        strcpy(ptr[height],tem);
                        cursor=len[height];
                    }else{
	                    cursor=len[height];
	                    mode=1;
                    }
                    mode=1;
                    re=1;
                    cont=0;
                }
                else if(s[i]=='a'){
                    if(i>0 && isdigit(s[i-1]) && re>0&&s[i+1]!='E'){
                        //memset(tem,'\0',sizeof(tem));
                    	//printf("%s\n",tem);
                        //printf("%d\n",len[height]);
                        int tr=i;
                        while(s[tr]!='E' || s[tr+1]!='S' || s[tr+2]!='C'){
                        	tr++;
                        }
                        int ch=tr-i-1;
                        int temc=0;
                        if(len[height]>0){
                            for(temc=0;temc<=cursor;temc++){
                                tem[temc]=ptr[height][temc];
                            }
                        }
                        for(int j=0;j<re;j++){
                            for(int ii=0;ii<ch;ii++){
                                tem[temc]=s[i+ii+1];
                                temc++;
                            }
                        }
                        if(len[height]>0){
                            for(int j=cursor+1;j<len[height];j++){
                                tem[temc]=ptr[height][j];
                                temc++;
                            }
                            free(ptr[height]);
                        }
                        if(len[height]>0)
                        	cursor=cursor+1+ch*re;
                        else if(len[height]==0){
                            cursor=ch*re;
                        }
                        len[height]=len[height]+ch*re;
                        tem[len[height]]='\0';
                        ptr[height]=(char*)malloc(sizeof(char)*(len[height]+1) );
                        strcpy(ptr[height],tem);
                        i+=ch;
                        //printf("%d\n",height);
                        //printf("%d\n",len[height]);
                    }else{
                    if(len[height]!=0){
                        cursor++;
                        }
                        mode=1;
                    }
                    re=1;
                    mode=1;
                    cont=0;
                }else if(s[i]=='h'){
                    cont=0;
                    cursor-=re;
                    if(cursor<0)
                        cursor=0;
                    re=1;
                }else if(s[i]=='l'){
                    cont=0;
                    cursor=max( min(cursor+re,len[height]-1),0 );
                    re=1;
                    //printf("%d\n",cursor);
                }else if(isdigit(s[i])){
                    re=s[i]-'0';
                    while(isdigit(s[i+1]) ){
                        i++;
                        re=re*10+s[i]-'0';
                    }
                }else if(s[i]=='x'){
                    cont=0;
                    re=min(re,len[height]-cursor);
                    if(len[height]>0){
                        for(int j=cursor;j<len[height]-re;j++){
                            ptr[height][j]=ptr[height][j+re];
                        }
                        if(len[height]-re==0)
                            free(ptr[height]);
                    }
                    len[height]=max(len[height]-re,0);
                    cursor=max(min(cursor,len[height]-1),0 );
                    re=1;
                }else if(s[i]=='k'){
                    if(cont==0){
	                    cont=1;
	                    cont_num=cursor;
                    }
                    height=max(0,height-re);
                    if(len[height]<=cont_num)
                    	cursor=max(len[height]-1,0);
                    else{
                        cursor=cont_num;
                    }
                    re=1;
                }else if(s[i]=='j'){
                    if(cont==0){
	                    cont=1;
	                    cont_num=cursor;
                    }
                    //printf("%d\n",cursor);
                    height=min(999,height+re);
                    if(len[height]<=cont_num)
                    	cursor=max(len[height]-1,0);
                    else{
                        cursor=cont_num;
                    }
                    re=1;
                }
            }
        }
        for(int i=0;i<1000;i++){
            if(len[i]>0)
                ptr[i][len[i]]='\0';
        }
        //printf("%d\n",cursor);
        //printf("%d\n",cont_num);
        printf("Case #%d:\n",times);
        int pr;
        for(pr=0;pr<1000;pr++){
            if(len[pr]>0 ){
                printf("%d: %s\n",pr+1,ptr[pr]);
                free(ptr[pr]);
            }
        }
        memset(s,'\0',sizeof(s));
    }
}
