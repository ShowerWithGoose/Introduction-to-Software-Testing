#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

#define max(a, b) ((a)>(b)? a : b)
int pan(char l, char r){
    if (r-l>1) { // @@ [The condition `r-l>1` is incorrect; expansion should occur even when r-l==2 (e.g., 'a'-'c' -> 'b'), but this skips cases where only one character is between them. Also, the logic for checking same type is flawed.]
        if (isdigit(l)* isalpha(r)) { // @@ [This condition checks if one is digit and the other is alpha, which should NOT be expanded. Multiplying booleans here is logically wrong; it should return 0 for such mixed cases, not 1.]
            return 1;
        }
        if (isalpha(l)* isalpha(r)) {
            if (isupper(l)* isupper(r)|| islower(l)* islower(r)) { // @@ [Using multiplication of boolean results (`isupper(l)*isupper(r)`) is error-prone; it works numerically but is unclear and may lead to mistakes. More critically, the function returns 1 only when r-l>1, which excludes valid expansions like 'a-b'.]
                return 1;
            }
        }
    }
    return 0;
}

int main() {

    char s[1000001];
    gets(s); // @@ [`gets()` is unsafe and deprecated; more importantly, in many modern environments it's removed, causing compilation errors. Should use `fgets()` or `scanf()`. This likely causes the "gcc: not found" error indirectly due to failed compilation in strict environments.]
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