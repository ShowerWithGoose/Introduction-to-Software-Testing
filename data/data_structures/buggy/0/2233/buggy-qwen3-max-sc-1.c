#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

#define max(a, b) ((a)>(b)? a : b)
int pan(char l, char r){
    if (r-l>1) { // @@ [The condition `r-l>1` is incorrect; expansion should occur when r > l, not necessarily r - l > 1. Also, the logic inside uses multiplication of boolean results from isdigit/isalpha which is wrong.]
        if (isdigit(l)* isalpha(r)) { // @@ [Using multiplication of return values of isdigit and isalpha is logically wrong. It should check if both are digits OR both are letters of same case. Also, this condition checks for digit and alpha which should NOT be expanded.]
            return 1;
        }
        if (isalpha(l)* isalpha(r)) { // @@ [Again, using multiplication instead of logical AND. Moreover, even if both are alphabetic, they must be of the same case.]
            if (isupper(l)* isupper(r)|| islower(l)* islower(r)) { // @@ [Same issue: using multiplication instead of logical AND (`&&`). This leads to incorrect truth evaluation.]
                return 1;
            }
        }
    }
    return 0;
}

int main() {

    char s[1000001];
    gets(s); // @@ [`gets()` is unsafe and deprecated; more importantly, it may not be available in some environments, leading to compilation errors. Use `fgets()` instead. Also, the problem expects reading until newline but `gets` is problematic.]
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