#include<stdio.h>
#include<string.h>
#include<stdbool.h>

int num,box;	//num:reel個數，需要一個box來記錄每個箱子有多大 
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
			/*跳過箱子大小為小數點的情況*/
			if(sum%i==0){
				box=sum/i;	//取得箱子大小 
				memset(vis,false,sizeof(vis));
				if(dfs(0,0)){
					/*不能在這邊printf("技能個數=%d\n",i);
					因為dfs(0,0)有可能是false(意即i==1)
					進而不會印出任何答案*/ 
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
	if(count==num){		//如果目前的count==卷軸數，代表這組數字ok
		return true;
	}
	
	int i;
	for(i=0;i<num;i++){		//每個卷軸都試試看 
		if(vis[i])	continue;	//如果這個卷軸用過了，就直接看下一個 
		vis[i]=true;	//把這個卷軸設為用過 
		if(sum+reel[i]<box){	//如果這個卷軸丟進箱子裡還沒滿，就可以直接丟 
			if( dfs(count+1,sum+reel[i]) ){
				return true;
			}
			/*母湯:return dfs(count+1,sum+reel[i]);*/
		}else if(sum+reel[i]==box){		//如果這個卷軸丟進箱子裡剛剛好，就可以直接丟並開一個新的箱子(sum=0) 
			if( dfs(count+1,0) ){
				return true;
			}
			/*母湯:return dfs(count+1,0);*/
		}
		vis[i]=false;	//記得將這個卷軸設為沒有用過
	}
	return false;	//如果每個卷軸都失敗就return false 
}
