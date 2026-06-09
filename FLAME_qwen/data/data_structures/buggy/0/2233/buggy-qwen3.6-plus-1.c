#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

#define max(a, b) ((a)>(b)? a : b)
int pan(char l, char r){
    if (r-l>1) { // @@ Logical error: The condition should be r > l to allow expansion of adjacent characters (e.g., a-b). r-l>1 incorrectly skips cases where the difference is exactly 1.
        if (isdigit(l)* isalpha(r)) { // @@ Logical error: This checks for different types (digit and letter), violating the "same type" requirement. It should check if both characters are digits.
            return 1;
        }
        if (isalpha(l)* isalpha(r)) {
            if (isupper(l)* isupper(r)|| islower(l)* islower(r)) {
                return 1;
            }
        }
    }
    return 0;
}

int main() {

    char s[1000001];
    gets(s); // @@ Compilation error: gets() is deprecated and removed in the C11 standard, causing compilation failure in modern environments. Use fgets() or scanf() instead.
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