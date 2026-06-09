#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

#define max(a, b) ((a)>(b)? a : b)
int pan(char l, char r){
    if (r-l>1) {
        if (isdigit(l)* isalpha(r)) { // @@ The condition uses multiplication instead of logical AND, which may produce incorrect results. Also, the logic is wrong: it should check if both are digits or both are letters of the same case, not mixed types.
            return 1;
        }
        if (isalpha(l)* isalpha(r)) { // @@ Same issue: multiplication instead of logical AND. Also, the condition should check that both are letters of the same case, but the logic is flawed.
            if (isupper(l)* isupper(r)|| islower(l)* islower(r)) { // @@ Multiplication instead of logical AND. This will not correctly check if both are uppercase or both are lowercase.
                return 1;
            }
        }
    }
    return 0;
}

int main() {

    char s[1000001];
    gets(s); // @@ gets() is unsafe and deprecated; it can cause buffer overflow. Use fgets() instead.
    int len = strlen(s);
    for (int i = 0; i <len ; i++) {
        if (s[i]!='-') {
            putchar(s[i]);
        }
        else{
            if (i==0||i==len-1) {
                putchar('-');
            }
            else{
                if (pan(s[i-1],s[i+1])) {
                    for (int j = s[i-1]+1; j <s[i+1] ; j++) {
                        putchar(j);
                    }
                }
                else{
                    putchar('-');
                }
            }
        }
    }
    return 0;
}