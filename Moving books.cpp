#include<stdio.h>
int address[25];
int table[25][25];

//將指定書號的書送往指定桌子的最上層
void sendbook(int booknum,int to){
    int i;
    
    //找出目的地桌子第幾號開始有空位
    for(i=0;table[to][i]!=-1;i++);

	//將空位放入書、將原本位置清空成-1
    table[to][i]=booknum;
    table[ address[booknum] / 100 ][ address[booknum] % 100 ]=-1;
    
	//更改書本位置
    address[booknum]=to*100+i;
}

//把指定的書之上的書送回其原桌子
void returnbookabove(int booknum){
	int i;
    int table_ofbook = address[booknum]/100;
    int index_ofbook = address[booknum]%100;

	//找到指定的書所在的桌子、從下一本開始依序送回其原桌
    for(i=index_ofbook+1;table[table_ofbook][i]!=-1;i++)
        sendbook(table[table_ofbook][i],table[table_ofbook][i]);
}

//將兩本書之上的書送回後，將a送往b所在的桌上
void moveonto(int a,int b){
    returnbookabove(a);
    returnbookabove(b);
    sendbook(a,address[b] / 100);
}

//將a之上的書送回後 將a送往b所在的桌上
void moveover(int a,int b){
    returnbookabove(a);
    sendbook(a,address[b] / 100);
}

//將b之上的書送回後 將a以上的書送往b所在的桌上
void pileonto(int a,int b){
	int i;
    returnbookabove(b);
    
    //從a的桌子、位置開始向上找，一本一本依序送往目的地
    int table_of_a=address[a] / 100;
    for(i=address[a]%100;table[table_of_a][i]!=-1;i++)
        sendbook(table[table_of_a][i],address[b]/100);
}

//將a以上的書 送往b所在的桌上
void pileover(int a,int b){
	int i;
	
	//從a的桌子、位置開始向上找，一本一本依序送往目的地
    int table_of_a=address[a]/100;
    for(i=address[a]%100;table[table_of_a][i]!=-1;i++)
        sendbook(table[table_of_a][i],address[b]/100);
}

int main(){
	int i,j;
    int n,a,b;
    char str1[5],str2[5];
    scanf("%d",&n);

	//初始化書的地址
    for(i=0;i<n;i++)
        address[i]=i*100;
    
	//初始化陣列
    for(i=0;i<n;i++){
        table[i][0]=i;
        for(j=1;j<n;j++)
        	table[i][j]=-1;
    }
    
    while(scanf("%s",str1)){
        if(str1[0]=='e')
            break;

        scanf("%d%s%d",&a,str2,&b);

        if(a==b || address[a]/100==address[b]/100)  //同一張桌子
            continue;

        if(str1[0]=='m' && str2[1]=='n')
            moveonto(a,b);
        else if(str1[0]=='m' && str2[1]=='v')
            moveover(a,b);
        else if(str1[0]=='p' && str2[1]=='n')
            pileonto(a,b);
        else
            pileover(a,b);
    }

    for(i=0;i<n;i++){
        printf("%d:",i);
        for(j=0;table[i][j]!=-1;j++)
            printf(" %d",table[i][j]);
        printf("\n");
    }
    return 0;
}
