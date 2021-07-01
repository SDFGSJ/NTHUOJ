#include<stdio.h>
#include<string.h>

/*num:h,l,x�e���Ʀr*/
int cur,mode,len,num;
char input[210];

int max(int a,int b)
{
	if(a>b)	return a;
	else if(a<b)	return b;
	else	return a;
}
int min(int a,int b)
{
	if(a<b)	return a;
	else if(a>b)	return b;
	else	return a;
}

int main(void)
{
	int i;
	while(scanf("%s",input)!=EOF)
	{
		char ans[510]={'\0'};
		/*�@�}�l�Ocommand mode�A�Sh,l,x�w�]���ާ@�@���ҥHnum=1*/ 
		cur=0, len=0, mode=0, num=1;	//0:command,1:insert
		for(i=0;input[i]!='\0';i++)
		{
			if(input[i]==':' && input[i+1]=='w' && input[i+2]=='q')	break;
			if(mode==0){	//command mode
				switch(input[i]){
					case 'a':	//enter insert mode after cursor
						if(len!=0){	//�p�G�r����פ���0  cur++�A�_�hcur=0
							cur++;
						}
						/*cur+=(len!=0);*/
						mode=1;
						break;
					case 'A':	//enter insert mode at the end of the line
						cur=len;	//cur����̫�
						mode=1;
						break;
					case 'i':	//enter insert mode before cursor
						/*cur���β���*/ 
						mode=1;
						break;
					case 'I':	//enter insert mode at the beginning of the line
						cur=0;
						mode=1;
						break;
					case 'h':	//left
						cur-=num;
						if(cur<0)	cur=0;	//�p�Gcur�w�g�ܦ��t���N�⥦�k0 
						num=1;
						break;
					case 'l':	//right
						/*min():�ˬd���S���W�ɡA�S���W��:cur+=num | ���W��:cur=len-1*/
						/*max():�U�@�O�Ŧr��(len-1=-1)�N��cur=0*/
						cur=max( min(cur+num,len-1), 0 );
						num=1;
						break;
					case 'x':	//delete the character at the cursor
						/*min{ ���R���r�� , cur�H�᪺�r�� }*/ 
						num=min(num,len-cur);
						for(int j=cur;j<len-num;j++){	//�h�r 
							ans[j]=ans[j+num];
						}
						//len=len-num;�o�˷|AC(�ǩǪ� 
						len=max(len-num,0);
						/*min():�ˬd���S����n�R��cur�᭱�Ҧ����r�A�S��:cur�ݦb��� | ��:cur�]��len-1
						  max():�U�@�R����O�Ŧr��(len-1=-1)�N��cur=0*/
						cur=max( min(cur,len-1), 0 );
						num=1;
						break;
					case '1'...'9':
						num=input[i]-'0';
						while('0'<=input[i+1] && input[i+1]<='9')
						{
							i++;
							num=num*10+input[i]-'0';
						}
						break;
					default:
						break;
				}
			}else{	//insert mode
				if(input[i]=='E' && input[i+1]=='S' && input[i+2]=='C'){
					mode=0;		//switch to command mode
					cur=max(cur-1,0);	//�p�G���O�Ŧr��cur=cur-1;�O�N��cur=0 
				}else{
					/*�p�Gcur����m�b�r��̫᭱(�N�Ylen==cur)�N���|�i�Jfor�j�鰵right shift*/
					for(int j=len;j>cur;j--){	//right shift
						ans[j]=ans[j-1];
					}
					ans[cur]=input[i];
					cur++,len++;
				}
			}
		}
		ans[len]='\0';	//�̫�O�o��@��'\0'�A�]���S����ڱN�r�]��' '�A�ӬO�ȹ�index�ާ@
		printf("%s\n",ans);
	}
	return 0;	
}
