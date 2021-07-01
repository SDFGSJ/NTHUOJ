#include<stdio.h>
#include<ctype.h>
int main(void)
{
	char a;
	int shift,num,cvt;
	scanf("%c%d",&a,&shift);
	/*先判斷輸入的是大寫還是小寫英文字母*/ 
	
	if(isupper(a)){
		//如果是大寫就+32變小寫 
		num=a+32-shift;
		//如果在範圍內就直接印出來 
		if(97<=num && num<=122)
			printf("%c\n",num);
		//如果低於97'a'就+26
		if(num<97)
			printf("%c\n",num+26);
		//如果高於122'z'就-26
		if(num>122)
			printf("%c\n",num-26);	
	}else{
		//如果是小寫就-32變大寫 
		num=a-32-shift;
		//如果在範圍內就直接印出來 
		if(65<=num && num<=90)
			printf("%c\n",num);
		//如果低於65'A'就+26
		if(num<65)
			printf("%c\n",num+26);
		//如果高於90'Z'就-26
		if(num>90)
			printf("%c\n",num-26);
	}
	return 0;
}
