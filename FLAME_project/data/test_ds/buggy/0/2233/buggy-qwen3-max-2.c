#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

#define max(a, b) ((a)>(b)? a : b)
int pan(char l, char r){
    if (r-l>1) { // @@ [The condition `r-l>1` is incorrect. Expansion should occur when `r > l`, even if they are consecutive (e.g., '0' and '1'). This prevents valid expansions like '0-1'.]
        if (isdigit(l)* isalpha(r)) { // @@ [This condition checks for digit-alpha mix, which should NOT be expanded. But due to multiplication (`*`), it returns non-zero only if both are true, which never happens since a char can't be both digit and alpha. However, the logic is inverted: this block should not allow expansion for mixed types, but the real issue is that this entire structure misrepresents the same-type requirement.]
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