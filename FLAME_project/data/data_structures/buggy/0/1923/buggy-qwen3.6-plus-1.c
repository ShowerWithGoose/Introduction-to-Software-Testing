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
    gets(s);
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
            else{ // @@ The 'else' block is only associated with the last 'if' statement (digits check). If the characters are letters (handled by previous 'if's), this 'else' is skipped, but the '-' is not printed. However, if the previous 'if's executed, we still need to ensure '-' isn't printed. The logic structure is flawed: it should be if-else if-else if-else. Currently, if it's uppercase, it expands, then checks lowercase (fails), then checks digits (fails), then executes else (prints '-'). This causes double output or incorrect output. Specifically for 'a-u', it enters the second 'if', expands, then falls through to the third 'if' (false), then executes 'else' printing '-'. So 'a-u' becomes 'bc...t-'.
                printf("-");
            }
        }
        else(printf("%c",s[i]));
    }
    return 0;
}