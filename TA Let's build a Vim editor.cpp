#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>

#define max(a, b) (a > b ? a : b)
#define min(a, b) (a < b ? a : b)

int main(void){
	char s[200]; // input
	while (scanf("%s", s) == 1) {
	    // Initialize
	    char answer[500] = {'\0'};
	    int cursor = 0; // current cursor
	    int length = 0;  // length of string
	    bool mode = false; //true: insert mode / false: command mode
	    int repeat = 1; // h,l,x command repeat time, default 1
	
	    for (int i = 0; s[i] != '\0'; i++) {
	      	if (s[i] == ':' && s[i + 1] == 'w' && s[i + 2] == 'q')
	        	break;
	      	if (!mode) {
	        	switch (s[i]) {
	        		case 'I':
	          			cursor = 0;
	          			mode = true;
	          			break;
	        		case 'i':
	          			mode = true;
	          			break;
	        		case 'A':
	         			cursor = length;
	          			mode = true;
	          			break;
	        		case 'a':
	          			cursor += (length != 0);
	          			mode = true;
	          			break;
	        		case 'x':
	          			repeat = min(repeat, length - cursor);
	          			for (int j = cursor; j < length - repeat; j++)
	            			answer[j] = answer[j + repeat];
	          			length = max(length - repeat, 0);
	          			cursor = max(min(cursor, length - 1), 0);
	          			repeat = 1;
	          			break;
	        		case 'h':
	          			cursor -= repeat;
	          			if (cursor < 0)
	            			cursor = 0;
	          			repeat = 1;
	          			break;
	        		case 'l':
	          			cursor = max(min(cursor + repeat, length - 1), 0);
	          			repeat = 1;
	          			break;
	        		case '1' ... '9':
	          			repeat = s[i] - '0';
	          			while (s[i + 1] >= '0' && s[i + 1] <= '9') {
	            			i++;
	            			repeat = repeat * 10 + s[i] - '0';
	          			}
			          	break;
			        default:
			          	break;
			        }
			} else {
		        if(s[i] == 'E' && s[i + 1] == 'S' && s[i + 2] == 'C'){
		          mode = false;
		          cursor = max(cursor - 1, 0);
		        }else{
		          for (int j = length; j > cursor; j--)
		        	answer[j] = answer[j - 1];
		          	answer[cursor++] = s[i];
		          	length++;
		        }
		    }
	    }
    	answer[length] = '\0';
    	printf("%s\n", answer);
	}
  	return 0;
}

