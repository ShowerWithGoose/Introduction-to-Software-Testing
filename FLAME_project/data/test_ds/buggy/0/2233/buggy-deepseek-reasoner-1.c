#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

#define max(a, b) ((a)>(b)? a : b)
int pan(char l, char r){
    if (r-l>1) {
        if (isdigit(l)* isalpha(r)) { // @@ Error: condition incorrectly allows expansion when left is digit and right is letter; should check both are digits. Also fails to handle digit-digit expansion.
            return 1;
        }
        if (isalpha(l)* isalpha(r)) { // @@ Error: missing condition for digit-digit; product of booleans is unconventional but works, but the overall logic fails to return 1 when both are digits.
            if (isupper(l)* isupper(r)|| islower(l)* islower(r)) {
                return 1;
            }
        }
    }
    return 0;
}

int main() {

    char s[1000001];
    gets(s);
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