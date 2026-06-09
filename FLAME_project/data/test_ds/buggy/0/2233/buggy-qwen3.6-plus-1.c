#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

#define max(a, b) ((a)>(b)? a : b)
int pan(char l, char r){
    if (r-l>1) { // @@ The condition r-l>1 incorrectly excludes adjacent characters (e.g., 'a' and 'b') from expansion. It should be l < r to check if the right character is strictly greater.
        if (isdigit(l)* isalpha(r)) { // @@ This incorrectly checks if l is a digit and r is a letter. It should verify both are digits: isdigit(l) && isdigit(r).
            return 1;
        }
        if (isalpha(l)* isalpha(r)) { // @@ Using * instead of logical && is incorrect for boolean checks. It should be isalpha(l) && isalpha(r).
            if (isupper(l)* isupper(r)|| islower(l)* islower(r)) { // @@ Using * instead of && and lacking parentheses for || precedence causes logical errors. It should be (isupper(l) && isupper(r)) || (islower(l) && islower(r)).
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