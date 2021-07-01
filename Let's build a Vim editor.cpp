#include<stdio.h>
#include<string.h>

/*num:h,l,x前的數字*/
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
		/*一開始是command mode，又h,l,x預設為操作一次所以num=1*/ 
		cur=0, len=0, mode=0, num=1;	//0:command,1:insert
		for(i=0;input[i]!='\0';i++)
		{
			if(input[i]==':' && input[i+1]=='w' && input[i+2]=='q')	break;
			if(mode==0){	//command mode
				switch(input[i]){
					case 'a':	//enter insert mode after cursor
						if(len!=0){	//如果字串長度不為0  cur++，否則cur=0
							cur++;
						}
						/*cur+=(len!=0);*/
						mode=1;
						break;
					case 'A':	//enter insert mode at the end of the line
						cur=len;	//cur移到最後
						mode=1;
						break;
					case 'i':	//enter insert mode before cursor
						/*cur不用移動*/ 
						mode=1;
						break;
					case 'I':	//enter insert mode at the beginning of the line
						cur=0;
						mode=1;
						break;
					case 'h':	//left
						cur-=num;
						if(cur<0)	cur=0;	//如果cur已經變成負的就把它歸0 
						num=1;
						break;
					case 'l':	//right
						/*min():檢查有沒有超界，沒有超界:cur+=num | 有超界:cur=len-1*/
						/*max():萬一是空字串(len-1=-1)就讓cur=0*/
						cur=max( min(cur+num,len-1), 0 );
						num=1;
						break;
					case 'x':	//delete the character at the cursor
						/*min{ 欲刪的字數 , cur以後的字數 }*/ 
						num=min(num,len-cur);
						for(int j=cur;j<len-num;j++){	//搬字 
							ans[j]=ans[j+num];
						}
						//len=len-num;這樣會AC(怪怪的 
						len=max(len-num,0);
						/*min():檢查有沒有剛好刪完cur後面所有的字，沒有:cur待在原位 | 有:cur設為len-1
						  max():萬一刪完後是空字串(len-1=-1)就讓cur=0*/
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
					cur=max(cur-1,0);	//如果不是空字串cur=cur-1;是就讓cur=0 
				}else{
					/*如果cur的位置在字串最後面(意即len==cur)就不會進入for迴圈做right shift*/
					for(int j=len;j>cur;j--){	//right shift
						ans[j]=ans[j-1];
					}
					ans[cur]=input[i];
					cur++,len++;
				}
			}
		}
		ans[len]='\0';	//最後記得塞一個'\0'，因為沒有實際將字設成' '，而是僅對index操作
		printf("%s\n",ans);
	}
	return 0;	
}
