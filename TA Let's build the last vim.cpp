#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>
#include<assert.h>

#define MAX_LINES 1000
#define max(a, b) (a > b ? a : b)
#define min(a, b) (a < b ? a : b)

#define NormalMode false
#define InsertMode true

char s[2010];
char buf[2010];

int main(){
	int T, testcase = 0;
	scanf("%d", &T);

	while(T--){
		scanf("%s", s);
		// Initialize
		char** ans = (char**)malloc( (MAX_LINES + 10) * sizeof(char*) );
		int* size = (int*)malloc( (MAX_LINES + 10) * sizeof(int) );
		int* capacity = (int*)malloc( (MAX_LINES + 10) * sizeof(int) );
		for(int i = 0; i < (MAX_LINES + 10); i++){
			size[i] = 0;
			capacity[i] = 1;
			ans[i] = (char*)malloc(sizeof(char));
		}
		int cursorX = 0;
		int cursorY = 0;
		int startX = -1;
		int repeat = 1;
		bool mode = NormalMode;

		for(int i = 0; s[i] != '\0'; i++){
			//printf("%d, %c, cursorX=%d, size[cursorY]=%d\n", i, s[i], cursorX, size[cursorY]);
			if(s[i] == ':' && s[i + 1] == 'w' && s[i + 2] == 'q') break;
		
			if(mode == NormalMode){
				if(s[i] == 'h' || s[i] == 'l' || s[i] == 'x'){
					if(s[i] == 'h'){
						cursorX = max(cursorX - repeat, 0);
					}else if (s[i] == 'l'){
						cursorX = max(min(cursorX + repeat, size[cursorY] - 1), 0);
					}else if (s[i] == 'x'){
						repeat = min(repeat, size[cursorY] - cursorX);
						for(int j = cursorX + repeat; j < size[cursorY]; j++)
							ans[cursorY][j - repeat] = ans[cursorY][j];
						size[cursorY] -= repeat;
						cursorX = max(min(cursorX, size[cursorY] - 1), 0);
					}
					repeat = 1;
					startX = -1;
				}else if (s[i] == 'j' || s[i] == 'k'){
					if(s[i] == 'j'){
						if(startX == -1) 
							startX = cursorX;
						cursorY = min(cursorY + repeat, MAX_LINES - 1);
						cursorX = max(min(startX, size[cursorY] - 1), 0);
					}else if (s[i] == 'k'){
						if(startX == -1) 
							startX = cursorX;
						cursorY = max(cursorY - repeat, 0);
						cursorX = max(min(startX, size[cursorY] - 1), 0);
					}
					repeat = 1;
				}else if(s[i] == 'a' || s[i] == 'A' || s[i] == 'i' || s[i] == 'I'){
					mode = InsertMode;
					if(s[i] == 'a'){
						cursorX = min(cursorX + 1, size[cursorY]);
					}else if(s[i] == 'A'){
						cursorX = size[cursorY];
					}else if(s[i] == 'i'){
						cursorX = cursorX;
					}else if(s[i] == 'I'){
						cursorX = 0;
					}
					startX = -1;
				}else if(s[i] >= '0' && s[i] <= '9'){
					repeat = s[i] - '0';
					while(s[i + 1] >= '0' && s[i + 1] <= '9'){
						i++;
						repeat = repeat * 10 + s[i] - '0';
					}
				}
			}else if(mode == InsertMode){
				if(s[i] == 'E' && s[i + 1] == 'S' && s[i + 2] == 'C'){
					mode = NormalMode;
					i += 2; // Skip ESC
					cursorX = max(cursorX - 1, 0);
				}else{
					int idx = 0;
					buf[idx++] = s[i];
					while(s[i + 1] >= 'a' && s[i + 1] <= 'z'){
						i++;
						buf[idx++] = s[i];
					}
					// Increase capacity if needed
					if (idx * repeat + size[cursorY] >= capacity[cursorY]) {
						while (idx * repeat + size[cursorY] >= capacity[cursorY]) {
							capacity[cursorY] *= 2;
						}
						char *copied = (char*)malloc(capacity[cursorY] * sizeof(char));
						for (int j = 0; j < size[cursorY]; j++)
							copied[j] = ans[cursorY][j];
						free(ans[cursorY]);
						ans[cursorY] = copied;
					}
				
					for (int j = size[cursorY] - 1; j >= cursorX; j--)
						ans[cursorY][j + idx * repeat] = ans[cursorY][j];
					for (int j = 0; j < idx * repeat; j++)
						ans[cursorY][j + cursorX] = buf[j % idx];
						
					size[cursorY] += idx * repeat;
					cursorX += idx * repeat;
				}
				repeat = 1;
			}
		}

		printf("Case #%d:\n", ++testcase);
		for (int i = 0; i < MAX_LINES; i++) {
			if (size[i] > 0) {
				ans[i][size[i]] = '\0';
				printf("%d: %s\n", i + 1, ans[i]);
			}
		}

		for (int i = 0; i < (MAX_LINES + 10); i++) {
			free(ans[i]);
		}
		free(size);
		free(capacity);
		free(ans);
	}
	return 0;
}
