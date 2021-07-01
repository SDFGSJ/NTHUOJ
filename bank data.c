#include<stdio.h>
#include<stdlib.h>
#include<string.h>
//#include "function.h"
typedef struct{
	char* name;
	int money;
}AccountData;

AccountData* createData(char* name, int money);
AccountData* userQuery(AccountData* data);

char s[100];
int money, attack_money;
AccountData* data;

int main(void){

    // store money in bank
    scanf("%s",s);
    scanf("%d",&money);
    scanf("%d",&attack_money);
    getchar(); // ignore newline
    AccountData* data = createData(s, money);

    // copy data and let user to query (handle process in bank)
    AccountData* userData = userQuery(data);

    // evil person try to attack
    userData->money = attack_money;

    // the money in bank
    printf("---money in bank---\nname: %s\nmoney: %d\n",data->name, data->money);
    if(data->money != userData->money){
        printf("warning! the user is try to modify the money in bank to %d\n",userData->money);
    }else{
        printf("query finish\n");
    }

    // free data
    free(userData->name);
    free(userData);
    free(data->name);
    free(data);
    return 0;
}
AccountData* createData(char* name, int money)
{
	int i;
	int len=strlen(name);
	AccountData *a = (AccountData*)malloc( sizeof(AccountData) );
	char* copy = (char*)malloc( len*sizeof(char) );
	/*for(i=0;i<len;i++){
		copy[i]=name[i];
	}*/
	strcpy(copy,name);
	a->money=money;
	a->name=copy;
	return a;
}
AccountData* userQuery(AccountData* data)
{
	int i;
	int len=strlen(data->name);
	AccountData* query = (AccountData*)malloc( sizeof(AccountData) );
	char *copy = (char*)malloc(len*sizeof(char));
	/*for(i=0;i<len;i++){
		copy[i]=(data->name)[i];
	}*/
	strcpy(copy,data->name);
	query->money=data->money;
	query->name=copy;
	return query;
}
