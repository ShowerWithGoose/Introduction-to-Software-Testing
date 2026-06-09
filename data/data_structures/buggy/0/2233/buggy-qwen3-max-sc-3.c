#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

#define max(a, b) ((a)>(b)? a : b)
int pan(char l, char r){
    if (r-l>1) { // @@ [The condition `r - l > 1` is incorrect. Expansion should occur when `r > l`, even if they are consecutive (e.g., 'a' and 'c' where r-l=2). But more critically, the logic inside uses multiplication of boolean results from isdigit/isalpha which is wrong.]
        if (isdigit(l)* isalpha(r)) { // @@ [Using multiplication (`*`) instead of logical AND (`&&`) leads to incorrect type checking. Also, this condition checks for digit-alpha mix, which should NOT be expanded per problem requirements.]
            return 1;
        }
        if (isalpha(l)* isalpha(r)) { // @@ [Again, using `*` instead of `&&`. This may accidentally work numerically but is logically wrong and misleading.]
            if (isupper(l)* isupper(r)|| islower(l)* islower(r)) { // @@ [Same issue: using `*` instead of `&&`. Also, this condition allows mixed case like 'A' and 'z' if both are alphabetic but not same case, but due to flawed logic it might not catch it correctly.]
                return 1;
            }
        }
    }
    return 0;
}

int main() {

    char s[1000001];
    gets(s); // @@ [`gets()` is unsafe and deprecated; it may cause buffer overflow. More importantly, in many modern environments, `gets()` is removed entirely, leading to compilation error. The reference program uses `scanf("%s", c)` which is safer and standard.]
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