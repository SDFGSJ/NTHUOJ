#include<stdio.h>//«Ýdebug 
int main(void)
{
	char map[3][3];
	int i,j,flag_o=0,flag_x=0;
	for(i=0;i<3;i++)
		for(j=0;j<3;j++)
			scanf("%s",&map[i][j]);
	//horizontal		
	for(i=0;i<3;i++){
		if(map[i][0]=='O'&&map[i][1]=='O'&&map[i][2]=='O'){
			flag_o=1;
			break;
		}else if(map[i][0]=='X'&&map[i][1]=='X'&&map[i][2]=='X'){
			flag_x=1;
			break;
		}
	}
	//vertical
	for(i=0;i<3;i++){
		if(map[0][i]=='O'&&map[1][i]=='O'&&map[2][i]=='O'){
			flag_o=1;
			break;
		}else if(map[0][i]=='X'&&map[1][i]=='X'&&map[2][i]=='X'){
			flag_x=1;
			break;
		}
	}
	//diagonal
	if(map[0][0]=='O'&&map[1][1]=='O'&&map[2][2]=='O' ||
		map[2][0]=='O'&&map[1][1]=='O'&&map[0][2]=='O')
	{
		flag_o=1;
	}else if(map[0][0]=='X'&&map[1][1]=='X'&&map[2][2]=='X' ||
			map[2][0]=='X'&&map[1][1]=='X'&&map[0][2]=='X')
	{
		flag_x=1;
	}
	/*for(i=0;i<3;i++){
		for(j=0;j<3;j++){
			printf("%c",map[i][j]);
		}
		printf("\n");
	}*/
	if(flag_o){
		printf("O wins!\n");
	}else if(flag_x){
		printf("X wins!\n");
	}else{
		printf("Draw!\n");
	}
					
	return 0;
}
