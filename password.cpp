#include<stdio.h>
#include<ctype.h>
int main(void)
{
	char a;
	int shift,num,cvt;
	scanf("%c%d",&a,&shift);
	/*���P�_��J���O�j�g�٬O�p�g�^��r��*/ 
	
	if(isupper(a)){
		//�p�G�O�j�g�N+32�ܤp�g 
		num=a+32-shift;
		//�p�G�b�d�򤺴N�����L�X�� 
		if(97<=num && num<=122)
			printf("%c\n",num);
		//�p�G�C��97'a'�N+26
		if(num<97)
			printf("%c\n",num+26);
		//�p�G����122'z'�N-26
		if(num>122)
			printf("%c\n",num-26);	
	}else{
		//�p�G�O�p�g�N-32�ܤj�g 
		num=a-32-shift;
		//�p�G�b�d�򤺴N�����L�X�� 
		if(65<=num && num<=90)
			printf("%c\n",num);
		//�p�G�C��65'A'�N+26
		if(num<65)
			printf("%c\n",num+26);
		//�p�G����90'Z'�N-26
		if(num>90)
			printf("%c\n",num-26);
	}
	return 0;
}
