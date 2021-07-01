#include <stdio.h>
#include <stdbool.h>
#include <string.h>
int val[4];
int output;
int count=0;
char s[40];

int prefix(){
    if(s[count]=='|' ){
        count++;
        int op1=prefix();
        int op2=prefix();
        return op1||op2;
    }
    else if(s[count]=='&'){
        count++;
        int op11=prefix();
        int op22=prefix();
        return op11&&op22;
    }
    else{
    return val[s[count++]-'A'];
    }
}
int main(){
    scanf("%s",s);
    for(int i=0;i<16;i++){
        int tem=i;
        for(int j=3;j>=0;j--){
            val[j]=tem%2;
            tem/=2;
        }
        count=0;
        output=prefix();

        for(int j=0;j<4;j++)
        printf("%d ",val[j]);
        printf("%d\n",output);
    }

