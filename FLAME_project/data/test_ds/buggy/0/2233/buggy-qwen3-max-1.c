#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

#define max(a, b) ((a)>(b)? a : b)
int pan(char l, char r){
    if (r-l>1) { @@ [The condition `r-l>1` is incorrect. Expansion should occur when `r > l`, even if they are consecutive (e.g., '0' and '1'). This prevents expansion for cases like '0-1'. Also, the logic inside uses multiplication instead of logical AND, which can lead to incorrect truth values.]
        if (isdigit(l)* isalpha(r)) { @@ [Using `*` (multiplication) instead of `&&` (logical AND) is wrong. This line checks if one is digit and the other is alpha, which should NEVER be expanded, yet it returns 1 (meaning expand). This is opposite of requirement.]
            return 1;
        }
        if (isalpha(l)* isalpha(r)) { @@ [Again, `*` should be `&&`. Also, this allows mixed case like 'A' and 'z' to pass as same type, which violates the requirement that both must be same case.]
            if (isupper(l)* isupper(r)|| islower(l)* islower(r)) { @@ [Same issue: `*` should be `&&`. Also, the outer `isalpha(l)*isalpha(r)` already passed, but this inner check is correct in intent but broken due to `*`.]
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