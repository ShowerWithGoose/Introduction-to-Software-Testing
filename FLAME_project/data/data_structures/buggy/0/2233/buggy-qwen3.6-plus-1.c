#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

#define max(a, b) ((a)>(b)? a : b)
int pan(char l, char r){
    if (r-l>1) { @@ The condition r-l>1 incorrectly prevents expansion when the characters are consecutive (e.g., '0' and '1', where r-l==1). The problem requires expanding ranges like '0-8', which includes consecutive steps. The check should likely be r > l, or handled by the loop logic. Furthermore, the logic inside is flawed for the specific test case.
        if (isdigit(l)* isalpha(r)) { @@ This condition checks if left is digit and right is alpha. For input '0-8', left is '0' (digit) and right is '8' (digit). isalpha('8') is 0, so this block is skipped. This logic is incorrect for digit-digit expansion.
            return 1;
        }
        if (isalpha(l)* isalpha(r)) { @@ This condition checks if both are alphabets. For '0-8', both are digits, so isalpha is 0 for both. This block is also skipped. Thus, pan returns 0 for valid digit ranges.
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