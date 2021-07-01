#include <stdio.h>
#include <stdbool.h>
#define MAX_SIZE 600
 
char content[MAX_SIZE];
char input[MAX_SIZE];
char temp[MAX_SIZE];
bool insertM = 1;
 
int main(void)
{
 
    fgets(input, MAX_SIZE, stdin);
    int i = 0, k = 0, j = 0;
    while(input[i] != 0 && input[i] != 10){
        //if(insertM){
            if(input[i] == '/'){
                i++;
                if(input[i] == 'L'){
                    if(k > 0){
                        temp[j++] = content[--k];
                    }
                    i++;
                }else if(input[i] == 'R'){
                    if(j > 0) content[k++] = temp[--j];
                    i++;
                }else if(input[i] == 'B'){
                    if(k > 0) k--;
                    content[k] = '\0';
                    i++;
                }else if(input[i] == 'n'){
                    content[k] = '\n';
                    k++;
                    i++;
                }else if(input[i] == 'I'){
                    insertM = !insertM;
                    //k--;
                    j--;
                    i++;
                }
 
            }
            else{
                content[k] = input[i];
                i++;
                k++;
            }
        //}
        /*else{
            k--;
        }*/
    }
    while(j > 0){
        content[k++] = temp[--j];
    }
    printf("%s", content);
 
    return 0;
}
