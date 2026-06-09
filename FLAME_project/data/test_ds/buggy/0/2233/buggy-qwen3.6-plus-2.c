#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

#define max(a, b) ((a)>(b)? a : b)
int pan(char l, char r){
    if (l < r) { // @@ Changed condition from r-l>1 to l<r to correctly handle adjacent characters and ensure left is strictly less than right
        if (isdigit(l) && isdigit(r)) { // @@ Fixed logic: originally checked if l is digit and r is alpha, should check if both are digits
            return 1;
        }
        if (isalpha(l) && isalpha(r)) { // @@ Use logical AND for correctness and clarity
            if (isupper(l) && isupper(r) || islower(l) && islower(r)) { // @@ Check if both characters are of the same case (both upper or both lower)
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