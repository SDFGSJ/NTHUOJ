#include<string.h>
int solver(int **ptr, int *sum, char *s)
{
	int i;
	int count=0,num=0,ok=0,sign=1;	//count:�Ʀr�ӼơBnum:�Ʀr�Bok:�O���O�Ʀr�Bsign:���t��(1��0�t) 
	int len=strlen(s);
	
	/*�p�G�̫�@�Ӧr���O�Ʀr���ܡA'i<len'�N�S��k�O����̫�@�ӼƦr
	�]��i�n�]��r�굲���~���|��|����Ʀr*/ 
	for(i=0;i<=len;i++){	
		if('0'<=s[i] && s[i]<='9'){
			num=num*10+s[i]-'0';
			ok=1;
		}else{	//�p�G�����O�Ʀr���� 
			if(ok){
				*ptr[count]=sign*num;	//�z�Lptr[]�����Ʀr 
				*sum+=sign*num;		//���K�[�` 
				count++;	//�Ʀr�Ӽ�+1 
			}
			if(s[i]=='-'){
				sign=-1;			
			}else{
				sign=1;		
			}
			ok=0;
			num=0;
		}
	}
	return count;
}
