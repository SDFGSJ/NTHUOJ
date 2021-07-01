#include<string.h>
int solver(int **ptr, int *sum, char *s)
{
	int i;
	int count=0,num=0,ok=0,sign=1;	//count:计计num:计ok:琌ぃ琌计sign:タ璽腹(1タ0璽) 
	int len=strlen(s);
	
	/*狦程じ琌计杠'i<len'碞⊿快猭癘魁程计
	i璶禲﹃挡Юぃ穦框簗ヴ计*/ 
	for(i=0;i<=len;i++){	
		if('0'<=s[i] && s[i]<='9'){
			num=num*10+s[i]-'0';
			ok=1;
		}else{	//狦ウぃ琌计杠 
			if(ok){
				*ptr[count]=sign*num;	//硓筁ptr[]魁计 
				*sum+=sign*num;		//抖獽羆 
				count++;	//计计+1 
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
