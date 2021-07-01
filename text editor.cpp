#include<stdio.h>
#include<string.h>
char content[550];
char input[550];
int len;
int cursor=0,l_bound=0,r_bound=0;
void shift_right();
void backspace();
int main(void)
{
	int i,j;	
    fgets(input,500,stdin);
	len=strlen(input);
	for(i=0;i<len;i++){
		if(input[i]!='/'){
			/*如果目前的游標不是在最尾巴(游標在字串中間)，則需要把每一個字都往右邊搬一格*/
			if(cursor!=r_bound){
				shift_right();			
			}
			content[cursor]=input[i];
			cursor++;
			r_bound++;
		}else{
			if(input[i+1]=='b'){
				backspace();
				i+=9;
			}else if(input[i+1]=='l'){
				/*如果游標不是在最左邊，就可以往左移*/ 
				if(cursor!=l_bound){
					cursor--;
				}
				i+=4;
			}else if(input[i+1]=='r'){
				/*如果游標不是在最右邊，就可以往右移*/
				if(cursor!=r_bound){
					cursor++;
				}
				i+=5;
			}else if(input[i+1]=='n'){
				/*如果目前的游標不是在最尾巴(游標在字串中間)，則需要把每一個字都往右搬一格再塞'\n'*/
				if(cursor!=r_bound){
					shift_right();
				}
				content[cursor]='\n';
				cursor++;
				r_bound++;
				i+=7;
			}
		}
		//printf("%s\n--------\n",content);
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
	/*如果游標已經到最左邊了，就不能再刪，return*/
	if(cursor==l_bound){
		return;
	/*如果游標在最右邊，就可以安心地刪*/
	}else if(cursor==r_bound){
		cursor--;
		r_bound--;
	/*如果游標在字串的中間，就要把cursor後面的每一個字都往前搬*/
	}else{
		int i;
		for(i=cursor;i<=r_bound;i++){
			content[i-1]=content[i];
		}
		cursor--;
		r_bound--;
	}
}
