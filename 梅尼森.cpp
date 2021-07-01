#include<stdio.h>
#include<math.h>	//因為會用到pow次方函數 
void mei(int);
int prime_check(long);	//檢查該long是否為質數 

int main(void)
{
	int n;
	scanf("%d",&n);
	mei(n);
	return 0;
}

void mei(int n)
{
	int time=0;		//已找到梅森質數的個數，因為一開始還沒找到半個，所以將它設為0 
	
	int i;	//迴圈變數
	 
	/*因為我們已知(2^1)-1並非質數，所以i從2開始跑*/	
	for(i=2;time<n;i++){	//只要它還沒有達到使用者輸入的數量就繼續跑
	
		long num=pow(2,i)-1;	//因為梅森質數一定是二的次方-1，所以就不用考慮非二次方的數字了 
		
		if(prime_check(num)==1){	//如果該數是質數 
			printf("%ld\n",num);	
			time++;		//找到的個數+1 
		}
	}
}

/*回傳1表示質數，0表示非質數 */
int prime_check(long num)
{
	int i;
	for(i=2;i<num;i++){		//這裡就不用糾結於一定要除一個質數，反正直接從2開始暴力除效果一樣，時間也差不多 
	
		if(num%i==0){	//如果這個數字可以被整除，就代表它不是質數，return 0 
			return 0;
		}
		
	}
	return 1;	//如果跑完所有數字都沒有辦法整除num，那就代表num是質數，return 1 
}
