#include<stdio.h>
#include<string.h>
char str0[2048];
char str1[2048];
long long len[65];
char find(int,long long);
int main(void)
{
	int i,t,n;	//��n��
	long long m;	//��m�Ӧr(�`�N�D�إi��|��long long�d��index) 
	scanf("%d",&t);
	while(t--)
	{
		scanf("%s%s",str0,str1);
		scanf("%d%lld",&n,&m);	//�o�䪺m�O�oscanf %lld
		len[0]=strlen(str0),len[1]=strlen(str1);
		for(i=2;i<60;i++){
			len[i]=len[i-1]+len[i-2];
		}
		/*for(i=0;i<60;i++){
			printf("%lld,",len[i]);
		}
		printf("\n");*/
		printf("%c\n",find(n,m));
	}
	return 0;
}
char find(int n,long long idx)	//��n��,��idx�Ӧr
{
	//basis step
	if(n==0){
		return str0[idx];
	}else if(n==1){
		return str1[idx];
	}
	//recursive step
	if(0<=idx && idx<len[n-2]){
		return find(n-2,idx);
	}else if(len[n-2]<=idx && idx<len[n]){
		return find(n-1,idx-len[n-2]);
	}
}
