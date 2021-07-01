void solver(char **ptr, int *n, int P, char *M)
{
	int i;
	int isnum=0,num=0;	//isnum:是不是數字、num:計算數字總和 
	int ptr_idx=0;	//ptr[]的index 
	int len=strlen(M);
	int number[1010];	//用來記錄num mod P的數字有沒有出現過，如果有就把number[num%P]設為1 
	memset(number,-1,sizeof(number);	//先把number[1010]的所有成員都設成-1(表示還沒有出現過) 
	for(i=0;i<len;i++){
		if('0'<=M[i] && M[i]<='9'){
			num=num*10+M[i]-'0';
			isnum=1;
		}else{
			number[num%P]=1;	//將number[num%P]改為1，表示該餘數出現過
			isnum=0;
			*ptr[num%P]=M[i];	//透過指標將該字元塞進Table[num%P][]裡 
			*(ptr[num%P]++);	//讓指標指向Table[num%P][]右邊一格的位址 
			
			/*如果這個字元的後面是一個數字，就代表該字串已經結束，
			要在其後塞一個'\0'並且將num歸0以計算下一個數字*/
			if('0'<=M[i+1] && M[i+1]<='9'){		 
				*ptr[num%P]='\0';
				num=0;
			}
		}
	}
	int count=0;	//紀錄一共有幾個單字 
	for(i=0;i<1010;i++){	//不知道可不可以改成i<P? 
		if(number[i]!=-1){	//如果這個餘數出現過，就代表在Table[num%P][]這個row裡面有東西
			count++;
		}
	}
	*n=count;
}
