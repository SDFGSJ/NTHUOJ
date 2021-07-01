#include<stdio.h>
char board[12][12];

int check_queen(int row,int col,int size);
int check_rooks(int row,int col,int size);
int put_chess(int row,int q,int r,int size);

int N,M;
int main(void){
    while(~scanf("%d%d",&N,&M)){
        printf("%d\n",put_chess(0,0,0,N+M));
    }
    return 0;
}
int check_queen(int row,int col,int size){
	int i;
    for(i=1;i<=row;i++){
        //�ˬd�﨤�u 
        if(0<=col-i && (board[row-i][col-i]=='Q' || board[row-i][col-i]=='R'))
            return 0;
        if(col+i<size && (board[row-i][col+i]=='Q' || board[row-i][col+i]=='R'))
            return 0;
        //�ˬd���� 
        if(board[row-i][col]=='Q' || board[row-i][col]=='R')
            return 0;
    }
    return 1;
}
int check_rooks(int row,int col,int size){
	//�����ˬd�׹﨤�W��rook 
	int i;
    for(i=1;i<=row;i++){
    	//�ˬd�﨤�u 
        if(col-i>=0 && board[row-i][col-i]=='Q')
            return 0;
        if(col+i<size && board[row-i][col+i]=='Q')
            return 0;
        //�ˬd���� 
        if(board[row-i][col]=='Q' || board[row-i][col]=='R')
            return 0;
    }
    return 1;
}
int put_chess(int row,int q,int r,int size){
    int i;
    //base case
	if(row==size){
        return 1;
    }
    
    int cnt=0;
    for(i=0;i<size;i++){
        if(q<N && check_queen(row,i,size)){	//��queen 
            board[row][i]='Q';
            cnt += put_chess(row+1,q+1,r,size);
            board[row][i]='0';	//�n���]���A 
        }
        if(r<M && check_rooks(row,i,size)){	//��rook 
            board[row][i]='R';
            cnt += put_chess(row+1,q,r+1,size);
            board[row][i]='0';	//�n���]���A 
        }
    }
    return cnt;
}
