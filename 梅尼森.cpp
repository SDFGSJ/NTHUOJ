#include<stdio.h>
#include<math.h>	//�]���|�Ψ�pow������ 
void mei(int);
int prime_check(long);	//�ˬd��long�O�_����� 

int main(void)
{
	int n;
	scanf("%d",&n);
	mei(n);
	return 0;
}

void mei(int n)
{
	int time=0;		//�w�����˽�ƪ��ӼơA�]���@�}�l�٨S���b�ӡA�ҥH�N���]��0 
	
	int i;	//�j���ܼ�
	 
	/*�]���ڭ̤w��(2^1)-1�ëD��ơA�ҥHi�q2�}�l�]*/	
	for(i=2;time<n;i++){	//�u�n���٨S���F��ϥΪ̿�J���ƶq�N�~��]
	
		long num=pow(2,i)-1;	//�]�����˽�Ƥ@�w�O�G������-1�A�ҥH�N���ΦҼ{�D�G���誺�Ʀr�F 
		
		if(prime_check(num)==1){	//�p�G�ӼƬO��� 
			printf("%ld\n",num);	
			time++;		//��쪺�Ӽ�+1 
		}
	}
}

/*�^��1��ܽ�ơA0��ܫD��� */
int prime_check(long num)
{
	int i;
	for(i=2;i<num;i++){		//�o�̴N���Ϊȵ���@�w�n���@�ӽ�ơA�ϥ������q2�}�l�ɤO���ĪG�@�ˡA�ɶ��]�t���h 
	
		if(num%i==0){	//�p�G�o�ӼƦr�i�H�Q�㰣�A�N�N�����O��ơAreturn 0 
			return 0;
		}
		
	}
	return 1;	//�p�G�]���Ҧ��Ʀr���S����k�㰣num�A���N�N��num�O��ơAreturn 1 
}
