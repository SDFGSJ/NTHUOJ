#include<stdio.h>
#include<string.h>
char password[25],secretpass[25],ans[50];
int ans0,len0,len1,temp0 = 0;
void dfs(char * a, char * b, int c){
    if(*a == '\0' && *b == '\0'){
        /*for(char * j = ans; *(j+1) != '\0'; j++){
            printf("%c",*j);
        }
        printf("\n");*/
        ans0++;
        return;
    }else if(*a == '\0' || *b == '\0') return;

    for(int i = c; i < len0; i++){
        if(*a == *b){
            dfs(a+1,b+1,i+1);
        }
        else if(*b == '#'){
            ans[temp0++] = *a;
            ans[temp0++] = ' ';
            dfs(a+1,b+1,i+1);
            ans[--temp0] = '\0';
            dfs(a+1,b,i+1);
            --temp0;
            return;
        }
        else if(*b == '$'){
            if(temp0 == 0 || ans[temp0-1] == ' ' || *a == *(a-1)){
            ans[temp0++] = *a;
            ans[temp0++] = ' ';
            dfs(a+1,b+1,i+1);
            ans[--temp0] = '\0';
            dfs(a+1,b,i+1);
            --temp0;
            }
            return;
        }
        else return;
    }


}

int main(){
    int a;
    scanf("%d",&a);
    while(a--){
        ans0 = 0;
        scanf("%s%s",password,secretpass);
        len0 = strlen(password);
        len1 = strlen(secretpass);
        dfs(password,secretpass,0);
        printf("%d\n",ans0);
    }

    return 0;
}

