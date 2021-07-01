#include<stdio.h>
int address[25];
int table[25][25];

//�N���w�Ѹ����Ѱe�����w��l���̤W�h
void sendbook(int booknum,int to){
    int i;
    
    //��X�ت��a��l�ĴX���}�l���Ŧ�
    for(i=0;table[to][i]!=-1;i++);

	//�N�Ŧ��J�ѡB�N�쥻��m�M�Ŧ�-1
    table[to][i]=booknum;
    table[ address[booknum] / 100 ][ address[booknum] % 100 ]=-1;
    
	//���ѥ���m
    address[booknum]=to*100+i;
}

//����w���Ѥ��W���Ѱe�^����l
void returnbookabove(int booknum){
	int i;
    int table_ofbook = address[booknum]/100;
    int index_ofbook = address[booknum]%100;

	//�����w���ѩҦb����l�B�q�U�@���}�l�̧ǰe�^����
    for(i=index_ofbook+1;table[table_ofbook][i]!=-1;i++)
        sendbook(table[table_ofbook][i],table[table_ofbook][i]);
}

//�N�⥻�Ѥ��W���Ѱe�^��A�Na�e��b�Ҧb����W
void moveonto(int a,int b){
    returnbookabove(a);
    returnbookabove(b);
    sendbook(a,address[b] / 100);
}

//�Na���W���Ѱe�^�� �Na�e��b�Ҧb����W
void moveover(int a,int b){
    returnbookabove(a);
    sendbook(a,address[b] / 100);
}

//�Nb���W���Ѱe�^�� �Na�H�W���Ѱe��b�Ҧb����W
void pileonto(int a,int b){
	int i;
    returnbookabove(b);
    
    //�qa����l�B��m�}�l�V�W��A�@���@���̧ǰe���ت��a
    int table_of_a=address[a] / 100;
    for(i=address[a]%100;table[table_of_a][i]!=-1;i++)
        sendbook(table[table_of_a][i],address[b]/100);
}

//�Na�H�W���� �e��b�Ҧb����W
void pileover(int a,int b){
	int i;
	
	//�qa����l�B��m�}�l�V�W��A�@���@���̧ǰe���ت��a
    int table_of_a=address[a]/100;
    for(i=address[a]%100;table[table_of_a][i]!=-1;i++)
        sendbook(table[table_of_a][i],address[b]/100);
}

int main(){
	int i,j;
    int n,a,b;
    char str1[5],str2[5];
    scanf("%d",&n);

	//��l�ƮѪ��a�}
    for(i=0;i<n;i++)
        address[i]=i*100;
    
	//��l�ư}�C
    for(i=0;i<n;i++){
        table[i][0]=i;
        for(j=1;j<n;j++)
        	table[i][j]=-1;
    }
    
    while(scanf("%s",str1)){
        if(str1[0]=='e')
            break;

        scanf("%d%s%d",&a,str2,&b);

        if(a==b || address[a]/100==address[b]/100)  //�P�@�i��l
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
