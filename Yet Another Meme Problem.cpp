#include<stdio.h>
#include<string.h>
char b[10];	//ノじ皚ㄓ矪瞶材计よ獽眔琌碭计 
int main(void)
{
	int i;
	int t;
	long long a;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%lld%s",&a,b);
		long long len=strlen(b);	//b琌碭计 
		for(i=0;i<len;i++)	//浪琩9...999薄猵 
		{
			if(b[i]<'9')
				break;
		}
		if(i==len){	//狦琌99...9999钡b计
			printf("%lld\n",a*len);
		}else{
			printf("%lld\n",a*(len-1));	//玥碞(计-1)
		}
	}
	return 0;
}
