void solver(char **ptr, int *n, int P, char *M)
{
	int i;
	int isnum=0,num=0;	//isnum:�O���O�Ʀr�Bnum:�p��Ʀr�`�M 
	int ptr_idx=0;	//ptr[]��index 
	int len=strlen(M);
	int number[1010];	//�ΨӰO��num mod P���Ʀr���S���X�{�L�A�p�G���N��number[num%P]�]��1 
	memset(number,-1,sizeof(number);	//����number[1010]���Ҧ��������]��-1(����٨S���X�{�L) 
	for(i=0;i<len;i++){
		if('0'<=M[i] && M[i]<='9'){
			num=num*10+M[i]-'0';
			isnum=1;
		}else{
			number[num%P]=1;	//�Nnumber[num%P]�אּ1�A��ܸӾl�ƥX�{�L
			isnum=0;
			*ptr[num%P]=M[i];	//�z�L���бN�Ӧr����iTable[num%P][]�� 
			*(ptr[num%P]++);	//�����Ы��VTable[num%P][]�k��@�檺��} 
			
			/*�p�G�o�Ӧr�����᭱�O�@�ӼƦr�A�N�N��Ӧr��w�g�����A
			�n�b����@��'\0'�åB�Nnum�k0�H�p��U�@�ӼƦr*/
			if('0'<=M[i+1] && M[i+1]<='9'){		 
				*ptr[num%P]='\0';
				num=0;
			}
		}
	}
	int count=0;	//�����@�@���X�ӳ�r 
	for(i=0;i<1010;i++){	//�����D�i���i�H�令i<P? 
		if(number[i]!=-1){	//�p�G�o�Ӿl�ƥX�{�L�A�N�N��bTable[num%P][]�o��row�̭����F��
			count++;
		}
	}
	*n=count;
}
