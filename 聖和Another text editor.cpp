#include<stdio.h>
#include<string.h>
#define MAX_SIZE 605

char content[MAX_SIZE];
char input[MAX_SIZE];

int main(void)
{
	int i,j;
    int cursor=0;
    int flag=0;
    fgets(input, 600, stdin);
    int len=strlen(input);
    for(i=0;i<len-1;i++){
        //printf("%d", cursor);
        if(input[i]=='/'){
            if(input[i+1]=='I'){
				/*change mode*/            
                if(flag) 
					flag=0;
                else 
					flag=1;
				i++;	
            }
            else if(input[i+1]=='R'){                
                if(content[cursor]!='\0') 
					cursor++;
				i++;
            }
            else if(input[i+1]=='L'){              
                if(cursor!=0)
					cursor--;
				i++;
            }
            else if(input[i+1]=='B'){            
                if(cursor!=0){
                    cursor--;
                    for(j=cursor;j<600;j++){
                        content[j]=content[j+1];
                    }
                }
                i++;
            }
            else if(input[i+1]=='n'){         
                for(j=600;j>cursor;j--){
                    content[j]=content[j-1];
                }
                content[cursor]='\n';
                cursor++;
                i++;
            }
        }
        else{
        	//insert mode
            if(content[cursor]!='\0' && flag==0){
                for(j=600;j>cursor;j--){
                    content[j]=content[j-1];
                }
            }
            //replace mode
            /*�p�Gcursor���᭱�O'\n'�A�h������shift_right�A�A��r���b'\n'�e��*/
            else if(content[cursor]=='\n' && flag==1){
                for(j=600;j>cursor;j--){
                    content[j]=content[j-1];
                }
            }
            content[cursor]=input[i];
            cursor++;
        }
    //printf(" %s\n", content);
    }
    printf("%s",content);
    return 0;
}
