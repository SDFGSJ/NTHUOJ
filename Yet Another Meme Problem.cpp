#include<stdio.h>
#include<string.h>
char b[10];	//�Φr���}�C�ӳB�z�ĤG�ӼƦr�A��K�o���O�X��� 
int main(void)
{
	int i;
	int t;
	long long a;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%lld%s",&a,b);
		long long len=strlen(b);	//��b�O�X��� 
		for(i=0;i<len;i++)	//�ˬd9...999�����p 
		{
			if(b[i]<'9')
				break;
		}
		if(i==len){	//�p�G�O�Φp99...9999�A�������Wb�����
			printf("%lld\n",a*len);
		}else{
			printf("%lld\n",a*(len-1));	//�_�h�N���W(���-1)
		}
	}
	return 0;
}
