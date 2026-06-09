#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

#define max(a, b) ((a)>(b)? a : b)
int pan(char l, char r){
    if (r-l>1) { // @@ [This condition is incorrect. Expansion should occur even when r - l == 1 (e.g., '0' and '1'), but this skips it. Also, the logic for checking same type is flawed.]
        if (isdigit(l)* isalpha(r)) { // @@ [This checks if one is digit and the other is alpha, which should NOT be expanded. But it returns 1, incorrectly allowing expansion for mixed types.]
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
                if (pan(s[i-1],s[i+1])) { // @@ [The function 'pan' has incorrect logic: it allows mixed-type expansions and disallows valid expansions where r - l == 1.]
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