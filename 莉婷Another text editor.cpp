#include<stdio.h>
#include<string.h>
#define MAX_SIZE 600

char content[MAX_SIZE];
char input[MAX_SIZE];
int cursor=0,count=0;
int flag=0;

int main(void)
{
	int i,j;
    fgets(input,MAX_SIZE,stdin);
    int len=strlen(input);
    for(i=0;i<len;i++)
    {
        if(input[i]=='/')
        {
            if(input[i+1]=='B')
            {
                if(cursor>0)
                {
                    cursor--;
                    content[cursor]='\0';
                    for (j=cursor; j<count-1; j++)
                        content[j]=content[j+1];
                    content[count-1]='\0';
                    count--;
                }
                i+=1;
            }
            else if(input[i+1]=='n')
            {
                if(cursor<count)
                {
                    for(j=count;j>cursor;j--)
                        content[j]=content[j-1];
                }
                content[cursor]='\n';
                cursor++,count++;
                i+=1;
            }
            else if(input[i+1]=='L')
            {
                if(cursor>0)
                    cursor--;
                i+=1;
            }
            else if(input[i+1]=='R')
            {
                if(cursor<count)
                    cursor++;
                i+=1;
            }
            else if(input[i+1]=='I')
            {
                flag++;
                //replace
                if(flag%2==1)
                {
                    content[cursor]='\0';
                    for(j=cursor;j<count-1;j++)
                        content[j]=content[j+1];
                    count--;
                }
                i+=1;
            }
        }
        else if(input[i]!='\n')
        {
            if(cursor<count)
            {
                for(j=count;j>cursor;j--)
                    content[j]=content[j-1];
            }
            content[cursor]=input[i];
            cursor++,count++;
        }
    }
    printf("%s",content);
    return 0;
}
