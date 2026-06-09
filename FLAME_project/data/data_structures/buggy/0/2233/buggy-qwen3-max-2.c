#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

#define max(a, b) ((a)>(b)? a : b)
int pan(char l, char r){
    if (r-l>1) { // @@ [The condition `r-l>1` is incorrect. Expansion should occur when `r > l`, even if they are consecutive (e.g., '0' and '1'). This prevents expansion for cases like '0-1'. Also, the logic inside uses multiplication instead of logical AND, which can lead to incorrect truth values.]
        if (isdigit(l)* isalpha(r)) { // @@ [Using `*` (multiplication) instead of `&&` (logical AND) is wrong. This checks if both functions return non-zero, but multiplication can yield non-zero even when one is zero (e.g., 0 * 0 = 0, but 1 * 0 = 0 — however, the intent is logical conjunction). Moreover, this condition checks for digit and alpha together, which should NEVER be expanded (they are different types), so this entire condition is logically inverted.]
            return 1;
        }
        if (isalpha(l)* isalpha(r)) { // @@ [Again, `*` should be `&&`. Also, this allows mixed case like 'A' and 'z', which are both alphabetic but not same case — violating the requirement that both must be same type (lower, upper, or digit).]
            if (isupper(l)* isupper(r)|| islower(l)* islower(r)) { // @@ [Same issue: `*` should be `&&`. Also, the outer `if` already ensures both are alpha, but this inner check is correct in intent yet flawed in operator usage. However, due to earlier errors, this may not behave as expected.]
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
                if (pan(s[i-1],s[i+1])) { // @@ [The function `pan` has multiple logical errors (as noted above), causing it to return 0 for valid expansions like '0' and '8', hence no expansion occurs. Specifically, for input '0-8', `isdigit('0')` is true, `isalpha('8')` is false, so `isdigit(l)*isalpha(r)` is 0, and the second condition `isalpha(l)*isalpha(r)` is also 0, so `pan` returns 0, skipping expansion.]
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