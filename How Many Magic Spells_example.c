#include <stdio.h>
#include <string.h>
char a[2010], b[2010];
int L[2010], R[2010];
int dp[2010][2010];		//建表 

int main(void) {
  int T;
  int i,j;
  scanf("%d",&T);
  while(T--){
    scanf("%s%s",a,b);
    
    int n=strlen(a);
    int m=strlen(b);

    for(i=0;i<n;i++){	//因為是a字串在比，所以兩個迴圈範圍都是到n 
      L[i]=0;
      R[i]=0;
      for(j=0;j<n;j++)
        dp[i][j]=0;
    }

    for(i=n-1;i>=0;i--){
      int idx1=i,idx2=0;
      while(idx1<n && idx2<m && a[idx1]==b[idx2]) {
        idx1++;
        idx2++;
      }
      if(idx1!=i){
        L[i]++;
        R[idx1]++;
      }

      dp[i][i-1]=0;
      for (j=i;j<n;j++)
        dp[i][j]=dp[i][j-1]+L[j]-R[j];
    }

    int q;
    scanf("%d",&q);
    while(q--){
      int ql=0,qr=0;
      scanf("%d%d",&ql,&qr);
      printf("%d\n",dp[ql][qr]+1);	//+1:直接接合的方法 
    }
    
  }
  
  return 0;
}

