#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

#define max(a, b) ((a)>(b)? a : b)
int pan(char l, char r){
    if (r-l>1) { // @@ [The condition `r - l > 1` is incorrect. Expansion should occur when `r > l`, even if they are consecutive (e.g., 'a' and 'c' where r-l=2). But more critically, the logic inside uses multiplication of boolean results from isdigit/isalpha which is wrong.]
        if (isdigit(l)* isalpha(r)) { // @@ [Using multiplication (`*`) instead of logical AND (`&&`) leads to incorrect type checking. Also, this condition checks for digit-alpha mix which should NOT be expanded, yet returns 1 indicating it should expand. This is logically inverted.]
            return 1;
        }
        if (isalpha(l)* isalpha(r)) { // @@ [Again, using `*` instead of `&&`. While both being alphabetic is necessary, it's not sufficient—must also be same case.]
            if (isupper(l)* isupper(r)|| islower(l)* islower(r)) { // @@ [Same issue: using `*` instead of `&&`. This causes incorrect evaluation (e.g., if one is upper and one is lower, `isupper(l)*isupper(r)` could be 0, but due to operator precedence and integer multiplication, logic fails).]
                return 1;
            }
        }
    }
    return 0;
}

int main() {

    char s[1000001];
    gets(s); // @@ [`gets()` is unsafe and deprecated; more importantly, in many modern compilers/environments, it may not be available or cause compilation errors. The reference program uses `scanf`, which is safer and standard. This likely causes the "gcc: not found" error indirectly if the environment disallows `gets`, but more accurately, this is a compilation error due to `gets` being removed in C11+.]
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