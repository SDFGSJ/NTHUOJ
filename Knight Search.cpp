#include<stdio.h>
char str[11]="ICPCASIASG";
char map[105][105];
int dx[8]={-1,-2,-2,-1,1,2,2,1};
int dy[8]={2,1,-1,-2,-2,-1,1,2};
int n,count,haveans;
void walk(int,int,int);
int main(void)
{
	int i,j;
	scanf("%d",&n);
	getchar();	//注意換行 
	for(i=0;i<n;i++){
		for(j=0;j<n;j++){
			scanf("%c",&map[i][j]);
		}
	}
	for(i=0;i<n;i++){
		for(j=0;j<n;j++){
			if(map[i][j]=='I'){
				count=1;	//從str[count] 
				//printf("(%d,%d)\n",i,j);
				walk(i,j,count);
			}
		}
	}
	if(haveans){
		printf("YES\n");
	}else{
		printf("NO\n");
	}
	/*for(i=0;i<n;i++){
		for(j=0;j<n;j++){
			printf("%c",map[i][j]);
		}
		printf("\n");
	}*/
	return 0;
}
void walk(int i,int j,int idx)
{
	int k;
	if(idx==10){	//如果走到最後一個字 
		haveans=1;
		return;
	}else{
		for(k=0;k<8;k++){	//各種方向都走走看 
			if(0<=i+dx[k] && i+dx[k]<=n-1 && 0<=j+dy[k] && j+dy[k]<=n-1){	//注意邊界 
				if(map[ i+dx[k] ][ j+dy[k] ]==str[idx]){ //如果剛好是那個字 
					walk(i+dx[k],j+dy[k],idx+1);
				}
			}
		}
	}
}
