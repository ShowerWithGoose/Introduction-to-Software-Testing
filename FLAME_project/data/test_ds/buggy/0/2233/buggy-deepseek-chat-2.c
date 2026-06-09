#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

#define max(a, b) ((a)>(b)? a : b)
int pan(char l, char r){
    if (r-l>1) {
        if (isdigit(l)* isalpha(r)) { // @@ The condition uses multiplication instead of logical AND, which may produce non-zero results for unintended combinations. Also, the logic incorrectly allows expansion when one character is a digit and the other is a letter, which violates the requirement that both characters must be of the same type.
            return 1;
        }
        if (isalpha(l)* isalpha(r)) { // @@ Same multiplication issue; should use logical AND (&&) to correctly check if both are alphabetic.
            if (isupper(l)* isupper(r)|| islower(l)* islower(r)) { // @@ Same multiplication issue; should use logical AND (&&) to correctly check if both are uppercase or both are lowercase.
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