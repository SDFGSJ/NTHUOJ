#include<stdio.h>
char str[10010];
int l,r,k;
void right_shift(void);

int main(void)
{
	int i,j;
	int query,len;
	scanf("%s",str);
	scanf("%d",&query);
	for(i=0;i<query;i++)
	{
		scanf("%d%d%d",&l,&r,&k);
		l-=1,r-=1;	//���Nl,r�B�z��array index 
		len=r-l+1;	//���o�r����� 
		k%=len;	//�ݭn�h�X�Ӧr 
		for(j=0;j<k;j++)
		{
			right_shift();
		}
	}
	printf("%s\n",str);
	return 0;
}
void right_shift(void)
{
	int i;
	char temp=str[r];	//���N�̫�@�Ӧrstr[r]�O�_�� 
	for(i=r;i>l;i--)
		str[i]=str[i-1];	//�k��
	str[l]=temp;	//�̫�A��W�Ĥ@�Ӧrstr[l] 
}
