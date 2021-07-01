#include<stdio.h>
#include<string.h>

int len,mode,num,now,end;               
char s[250],ans[500];

int main(void){
	int i,j;
    while( ~scanf("%s",s) ){
        len=strlen(s);
		mode=now=num=end=0;
        for(i=0;i<len-3;i++){
            if(mode){	//insert mode
                if(s[i]=='E') 
					mode = 0;
					now? now-- : 0;
					i += 2;
                else{
                    for(j=end;j>now;j--) 
						ans[j] = ans[j-1];
                    ans[now] = s[i];
					now++,end++;
                }
            }else{		//command mode
                if('0'<=s[i] && s[i]<='9') 
					num = num*10+s[i]-'0';
                if(s[i]=='h') 
					num? now-=num : now--;
					num = 0;
                if(s[i]=='l') 
					num? now+=num : now++;
					num = 0;
                if(s[i]=='x'){
                    if(num==0) 
						num = 1;
                    if(end-now<num) 
						num = end-now;
                    for(j=now;j<end-num;j++) 
						ans[j] = ans[j+num];
                    end -= num;
					num = 0;
                }
                if(end-1<now) 
					now = end-1;
                if(now<0) 
					now = 0;
                if(s[i]=='a') 
					mode = 1;
					now += (end!=0);
                if(s[i]=='i') 
					mode = 1;
                if(s[i]=='A') 
					mode = 1;
					now = end;
                if(s[i]=='I') 
					mode = 1;
					now = 0;
            }
        }
        ans[end] = '\0';
        printf("%s\n",ans);
    }
}
