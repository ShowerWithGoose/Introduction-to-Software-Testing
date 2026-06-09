#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <ctype.h>
#define arrLen(x) (sizeof(x)/sizeof(x[0]))

char s[1000];
int main()
{
    int i;
    char c; 
    gets(s); // @@ Compilation error: 'gets' was removed from the C11 standard and causes compilation failure in modern compilers; use 'fgets(s, sizeof(s), stdin)' instead.
    for(i=0; i<strlen(s); i++){
        c='0';
        if(s[i] == '-'){
            if(s[i-1] >= 'A' && s[i-1] <= 'Z' && s[i+1] >= 'A' && s[i+1] <= 'Z'){
                c=s[i-1];
                while(c<s[i+1]-1){
                    c=c+1;
                    printf("%c",c);
                }
            }
            if(s[i-1] >= 'a' && s[i-1] <= 'z' && s[i+1] >= 'a' && s[i+1] <= 'z'){
                c=s[i-1];
                while(c<s[i+1]-1){
                    c=c+1;
                    printf("%c",c);
                }
            }
            if(s[i-1] >= '0' && s[i-1] <= '9' && s[i+1] >= '0' && s[i+1] <= '9'){
                c=s[i-1];
                while(c<s[i+1]-1){
                    c=c+1;
                    printf("%c",c);
                }
            }
            else{ // @@ Logical error: This 'else' only binds to the immediately preceding 'if' (digit check). It will execute and print '-' even when uppercase or lowercase expansion succeeds, resulting in incorrect output. It should be part of an 'if-else if-else' chain.
                printf("-");
            }
        }
        else(printf("%c",s[i])); // @@ Syntax/Logical issue: Unnecessary parentheses around the printf statement. While syntactically valid, it is poor style. The overall control flow for expansion is also flawed due to separate 'if' statements instead of 'else if'.
    }
    return 0;
}