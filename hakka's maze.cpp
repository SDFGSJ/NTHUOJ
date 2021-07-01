#include<stdio.h>
#include<string.h>
#include<stdbool.h>
int n,m;
char map[1010][1010];
bool walked[1010][1010];
bool can_teleport=false;

void walk(int,int);

int main(void)
{
	int t;
	int i,j;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d%d",&n,&m);
		for(i=0;i<n;i++){
			scanf("%s",map[i]);
		}
		
		memset(walked,false,sizeof(walked));
		can_teleport=false;
		walk(0,0);
		
		if(can_teleport){	//如果走完一遍dfs後有遇到teleport，就可以傳送過去 
			for(i=0;i<n;i++){
				for(j=0;j<m;j++){
					if(map[i][j]=='T'){
						walk(i,j);	//把這個teleport當作新的一個出發點 
					}
				}
			}
		}
		/*for(i=0;i<n;i++){
			printf("%s\n",map[i]);
		}*/
		/*for(i=0;i<10;i++){
			for(j=0;j<10;j++){
				if(walked[i][j]){
					printf("1");
				}else{
					printf("0");
				}
			}
			printf("\n");
		}*/
		if(walked[n-1][m-1])
			printf("Yes\n");
		else
			printf("No\n");		
	}
	return 0;
}
void walk(int row,int col)
{
	int i;	
	if(walked[row][col])
		return;		
	if(map[row][col]=='T')
		can_teleport=true;
		
	walked[row][col]=true;
	
	int dx[4]={-1,0,1,0};
	int dy[4]={0,1,0,-1};
	
	for(i=0;i<4;i++){
		//這裡不能row+=dx[i]與col+=dy[i]因為會爛掉(可自己debug) 
		int newrow=row+dx[i];
		int newcol=col+dy[i];
		if(newrow<0 || n<=newrow || newcol<0 || m<=newcol)	//如果出界就換一個方向走走看 
			continue;
		
		if(map[newrow][newcol]=='#')	//如果撞牆就換一個方向走走看
			continue;
		
		walk(newrow,newcol);
	}
}
