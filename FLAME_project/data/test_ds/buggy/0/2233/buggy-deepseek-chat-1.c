#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

#define max(a, b) ((a)>(b)? a : b)
int pan(char l, char r){
    if (r-l>1) {
        if (isdigit(l)* isalpha(r)) { // @@ The condition uses multiplication instead of logical AND, which may produce incorrect results. Also, it checks if one is digit and the other is alpha, but the problem requires both to be of the same type (digit-digit, lowercase-lowercase, or uppercase-uppercase). This condition is wrong.
            return 1;
        }
        if (isalpha(l)* isalpha(r)) { // @@ Same multiplication issue; should use logical AND (&&). Also, the logic for checking same case is flawed because it uses multiplication instead of proper logical operators.
            if (isupper(l)* isupper(r)|| islower(l)* islower(r)) { // @@ Same multiplication issue; should use logical AND (&&) for proper boolean evaluation.
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