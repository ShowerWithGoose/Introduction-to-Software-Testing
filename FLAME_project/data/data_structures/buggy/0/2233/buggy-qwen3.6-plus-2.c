#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

#define max(a, b) ((a)>(b)? a : b)
int pan(char l, char r){
    if (r-l>1) { @@ The condition r-l>1 incorrectly prevents expansion when the range is exactly 2 characters (e.g., '0' to '2' implies '1' is missing, but '0' to '1' has no middle chars. However, the main issue is logic below. Actually, for '0'-'8', r-l is 8, so this passes. But for 'a'-'c', r-l is 2, passes. The real error is in the type checking logic.)
        if (isdigit(l)* isalpha(r)) { @@ This condition checks if left is digit AND right is alpha. This is invalid for expansion. Expansion requires same types. This line should be removed or corrected. It returns 1 for mixed types like '0'-'a', which is wrong.
            return 1;
        }
        if (isalpha(l)* isalpha(r)) {
            if (isupper(l)* isupper(r)|| islower(l)* islower(r)) {
                return 1;
            }
        }
        if (isdigit(l) && isdigit(r)) { @@ Missing check for digits. The current code only handles alpha-alpha or digit-alpha (incorrectly). It fails to return 1 for digit-digit cases like '0' and '8'.
            return 1;
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