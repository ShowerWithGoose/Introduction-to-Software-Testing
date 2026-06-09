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
            else{ // @@ The 'else' block is only associated with the last 'if' statement (digits check). If the characters are letters (handled by previous 'if's), this 'else' is skipped, but the '-' is not printed. However, if the types don't match or order is wrong, none of the 'if's execute, and this 'else' prints '-'. But there is a logical flaw: if it's a valid letter expansion, the first or second 'if' runs. If it's NOT a valid expansion (e.g. a-R), none of the specific type checks pass, so it falls to this else. Wait, if it is a-z and A-Z mismatch, none of the 3 ifs are true, so else executes. This part is actually okay for printing '-'. The real issue is below.
                printf("-");
            }
        }
        else(printf("%c",s[i]));
    }
    return 0;
}