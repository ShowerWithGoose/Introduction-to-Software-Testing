#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

#define max(a, b) ((a)>(b)? a : b)
int pan(char l, char r){
    if (r-l>1) { // @@ [The condition `r-l>1` is incorrect. Expansion should occur when `r > l`, even if they are consecutive (e.g., 'a' and 'c' with gap 2). But more critically, the logic inside uses multiplication of boolean results from `isdigit`/`isalpha`, which is wrong.]
        if (isdigit(l)* isalpha(r)) { // @@ [Using multiplication (`*`) instead of logical AND (`&&`) leads to incorrect type checking. Also, this condition checks for digit vs alpha which should NOT be expanded, yet returns 1 meaning "expand", which is opposite of requirement.]
            return 1;
        }
        if (isalpha(l)* isalpha(r)) { // @@ [Again, using `*` instead of `&&`. This may accidentally work numerically but is logically incorrect and fragile.]
            if (isupper(l)* isupper(r)|| islower(l)* islower(r)) { // @@ [Same issue: using `*` instead of `&&`. Also, the overall structure allows expansion only when `r - l > 1`, but problem requires expansion whenever `r > l` (e.g., 'a'-'b' should expand to nothing between, but still valid and should not output '-'). However, the bigger issue is that the function returns 1 for invalid cross-type cases due to misuse of `isdigit * isalpha`.]
                return 1;
            }
        }
    }
    return 0;
}

int main() {

    char s[1000001];
    gets(s); // @@ [`gets()` is unsafe and deprecated; more importantly, it may not be available in modern compilers, leading to compilation error. The reference program uses `scanf("%s", c)` which is safe for this context. Using `gets()` can cause compilation failure if compiler enforces secure functions or doesn't support it.]
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