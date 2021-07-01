int changeCharacter(char *str, char a, char b)
{
	int i;
	int len=strlen(str);
	for(i=0;i<len;i++){
		if(str[i]==a){
			str[i]=b;
		}
	}
	return 1;
}
