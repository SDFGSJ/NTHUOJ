#include <stdio.h>
#include <limits.h>
char maze[505][505];
int m,n,all=0,minstep=INT_MAX;
void run(int,int,int);
int main(void)
{
    int time;
    scanf("%d",&time);
    while(time--)
    {
        scanf("%d%d",&m,&n);
        all=0,minstep=INT_MAX;
        for(int i=1;i<=m;i++) scanf("%s",maze[i]+1),maze[i][n+1]='\0';
        for(int i=1;i<=n;i++) maze[m+1][i]='\0';
        int startm,startn,flag=0;
        for(int i=1;i<=m&&flag==0;i++) for(int j=1;j<=n&&flag==0;j++) if(maze[i][j]=='S') startm=i,startn=j,flag=1;
        run(startm,startn,0);
        if(all) printf("%d\n",minstep);
        else printf("%d\n",-1);
    }
}
void run(int a,int b,int step)
{
    if(step>minstep) return;
    if(maze[a][b]=='F')
    {
        all=1;
        if(step<minstep) minstep=step;
    }
    else
    {
        maze[a][b]='R';
        if(maze[a-1][b]=='$'||maze[a-1][b]=='F') run(a-1,b,step+1);
        if(maze[a][b-1]=='$'||maze[a][b-1]=='F') run(a,b-1,step+1);
        if(maze[a][b+1]=='$'||maze[a][b+1]=='F') run(a,b+1,step+1);
        if(maze[a+1][b]=='$'||maze[a+1][b]=='F') run(a+1,b,step+1);
        maze[a][b]='$';
    }
}
