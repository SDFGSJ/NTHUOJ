#include<stdio.h>
#include<string.h>
#include<stdbool.h>

int num,box;	//num:reel�ӼơA�ݭn�@��box�ӰO���C�ӽc�l���h�j 
int reel[15];
bool vis[15];

bool dfs(int,int);

int main(void)
{
	int i;
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int sum=0;
		scanf("%d",&num);
		for(i=0;i<num;i++){
			scanf("%d",&reel[i]);
			sum+=reel[i];
		}
		for(i=num;i>1;i--){
			/*���L�c�l�j�p���p���I�����p*/
			if(sum%i==0){
				box=sum/i;	//���o�c�l�j�p 
				memset(vis,false,sizeof(vis));
				if(dfs(0,0)){
					/*����b�o��printf("�ޯ�Ӽ�=%d\n",i);
					�]��dfs(0,0)���i��Ofalse(�N�Yi==1)
					�i�Ӥ��|�L�X���󵪮�*/ 
					break;
				}
			}
		}
		printf("%d\n",i);
	}
	return 0;
}
bool dfs(int count,int sum)
{
	if(count==num){		//�p�G�ثe��count==���b�ơA�N��o�ռƦrok
		return true;
	}
	
	int i;
	for(i=0;i<num;i++){		//�C�Ө��b���ոլ� 
		if(vis[i])	continue;	//�p�G�o�Ө��b�ιL�F�A�N�����ݤU�@�� 
		vis[i]=true;	//��o�Ө��b�]���ιL 
		if(sum+reel[i]<box){	//�p�G�o�Ө��b��i�c�l���٨S���A�N�i�H������ 
			if( dfs(count+1,sum+reel[i]) ){
				return true;
			}
			/*����:return dfs(count+1,sum+reel[i]);*/
		}else if(sum+reel[i]==box){		//�p�G�o�Ө��b��i�c�l�̭��n�A�N�i�H������ö}�@�ӷs���c�l(sum=0) 
			if( dfs(count+1,0) ){
				return true;
			}
			/*����:return dfs(count+1,0);*/
		}
		vis[i]=false;	//�O�o�N�o�Ө��b�]���S���ιL
	}
	return false;	//�p�G�C�Ө��b�����ѴNreturn false 
}
