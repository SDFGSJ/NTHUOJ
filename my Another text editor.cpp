//from ¸t©M·Qªk
#include<stdio.h>
#include<string.h>

char input[610];
char content[610];

int cursor,r_bound,l_bound;
int mode;//0:insert, 1:replace

void shift_right();
void backspace();

int main(void)
{
	int i,j;
    fgets(input,610,stdin);
    
	int len=strlen(input);
    for(i=0;i<len-1;i++){
    	if(input[i]!='/'){
    		if(mode==0 && cursor!=r_bound){
    			shift_right();
			}else if(mode==1 && content[cursor]=='\n'){
				shift_right();
			}
			content[cursor]=input[i];
    		cursor++,r_bound++;	
		}else{
			if(input[i+1]=='B'){
				backspace();
				i++;
			}else if(input[i+1]=='L'){
				if(cursor!=l_bound){
					cursor--;
				}
				i++;
			}else if(input[i+1]=='R'){
				if(cursor!=r_bound){
					cursor++;
				}
				i++;
			}else if(input[i+1]=='n'){
				if(cursor!=r_bound){
					shift_right();
				}
				content[cursor]='\n';
				cursor++,r_bound++;				
				i++;
			}else if(input[i+1]=='I'){
				if(mode)
					mode=0;
				else
					mode=1;
				i++;
			}
		}
	}
    printf("%s",content);
    return 0;
}
void shift_right()
{
	int i;
	for(i=r_bound;i>=cursor;i--){
		content[i+1]=content[i];
	}
}
void backspace()
{
	int i;
	if(cursor==l_bound){
		return;
	}else if(cursor==r_bound){
		cursor--;
		r_bound--;
	}else{
		for(i=cursor;i<=r_bound;i++){
			content[i-1]=content[i];
		}
		cursor--;
		r_bound--;
	}
}
