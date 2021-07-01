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
			/*�p�G�ثe����Ф��O�b�̧���(��Цb�r�ꤤ��)�A�h�ݭn��C�@�Ӧr�����k��h�@��*/
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
				/*�p�G��Ф��O�b�̥���A�N�i�H������*/ 
				if(cursor!=l_bound){
					cursor--;
				}
				i+=4;
			}else if(input[i+1]=='r'){
				/*�p�G��Ф��O�b�̥k��A�N�i�H���k��*/
				if(cursor!=r_bound){
					cursor++;
				}
				i+=5;
			}else if(input[i+1]=='n'){
				/*�p�G�ثe����Ф��O�b�̧���(��Цb�r�ꤤ��)�A�h�ݭn��C�@�Ӧr�����k�h�@��A��'\n'*/
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
	/*�p�G��Фw�g��̥���F�A�N����A�R�Areturn*/
	if(cursor==l_bound){
		return;
	/*�p�G��Цb�̥k��A�N�i�H�w�ߦa�R*/
	}else if(cursor==r_bound){
		cursor--;
		r_bound--;
	/*�p�G��Цb�r�ꪺ�����A�N�n��cursor�᭱���C�@�Ӧr�����e�h*/
	}else{
		int i;
		for(i=cursor;i<=r_bound;i++){
			content[i-1]=content[i];
		}
		cursor--;
		r_bound--;
	}
}
