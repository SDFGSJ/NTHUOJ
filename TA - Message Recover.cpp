#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include <stdio.h>

int is_digit( char c ){
    return ( '0' <= c && c <= '9' );
}
int hash(int x, int P){
    return x % P;
}
void solver(char **ptr, int *n, int P, char *s){
    // Regular Expr verision
    int cnt = 0;
    int i = 0, len = strlen(s);
    char x_str[1001], word[1001];
    *n = 0;
    while( i < len ){
        int lx = 0;
        while( is_digit(s[i]) ){
            x_str[ lx++ ] = s[i++];
        }
		x_str[lx] = '\0';
        int lw = 0;
        while( i < len && !is_digit(s[i]) ){
            word[ lw++ ] = s[i++];
        }
        word[lw] = '\0';
        int x = atoi(x_str);
        int order = hash(x, P);
        // printf("%d %s\n", order, word);
        if( strlen(ptr[order]) == 0 ) *n += 1;
        strcat(ptr[order], word);
    }
}
