#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct _AccountData {

	char* name;

	int money;

} AccountData;
AccountData* createData(char* name, int money);
AccountData* userQuery(AccountData* data);
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
