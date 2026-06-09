#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

#define max(a, b) ((a)>(b)? a : b)
int pan(char l, char r){
    if (r-l>1) {
        if (isdigit(l)* isalpha(r)) { // @@ The condition uses multiplication of boolean results, which is incorrect. It should check if both are digits or both are letters, not mixing types. Also, the logic for expansion is wrong: it should only expand when both characters are of the same type (digit, lowercase, uppercase) and r > l.
            return 1;
        }
        if (isalpha(l)* isalpha(r)) { // @@ Same issue: multiplication of boolean results is not the correct way to check type compatibility. Should check if both are uppercase or both are lowercase.
            if (isupper(l)* isupper(r)|| islower(l)* islower(r)) { // @@ Again, multiplication of boolean results is incorrect. Should use logical AND (&&) instead.
                return 1;
            }
        }
    }
    return 0;
}

int main() {

    char s[1000001];
    gets(s); // @@ The gets() function is unsafe and deprecated; it can cause buffer overflow. Also, it does not match the problem's input format specification.
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