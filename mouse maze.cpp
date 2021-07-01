#include<stdio.h>
#include<limits.h>
char map[510][510];

int n,m;
int start_i,start_j;
int final_i,final_j;
int min_step=INT_MAX,haveAns=0;

void walk(int row,int col,int step);
void find(int row,int col);


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
		find(n,m);
		//printf("s®y¼Ð=%d,%d\n",start_i,start_j);
		//printf("f®y¼Ð=%d,%d\n",final_i,final_j);
		walk(start_i,start_j,0);
		/*for(i=0;i<n;i++){
			printf("%s\n",map[i]);
		}*/
		if(haveAns){
			printf("%d\n",min_step);
		}else{
			printf("-1\n");
		}

		min_step=INT_MAX;
		haveAns=0;
	}
	return 0;
}
void walk(int row,int col,int step)
{
	//basis step
	if(step>min_step)
		return;
	if(row==final_i && col==final_j){
		if(step<min_step){
			min_step=step;
			haveAns=1;
		}
	}else{
		//recursive step
		map[row][col]='#';
		if(row-1>=0 && (map[row-1][col]=='$' || map[row-1][col]=='F')){	//up			
			walk(row-1,col,step+1);						
		}
		if(col+1<m  && (map[row][col+1]=='$' || map[row][col+1]=='F')){	//right
			walk(row,col+1,step+1);			
		}
		if(row+1<n  && (map[row+1][col]=='$' || map[row+1][col]=='F')){	//down
			walk(row+1,col,step+1);		
		}
		if(col-1>=0 && (map[row][col-1]=='$' || map[row][col-1]=='F')){	//left
			walk(row,col-1,step+1);			
		}
		map[row][col]='$';
	}	
}
void find(int row,int col)
{
	int i,j;
	for(i=0;i<row;i++){
		for(j=0;j<col;j++){
			if(map[i][j]=='S'){
				start_i=i;
				start_j=j;
			}
			if(map[i][j]=='F'){
				final_i=i;
				final_j=j;
			}
		}
	}
}
