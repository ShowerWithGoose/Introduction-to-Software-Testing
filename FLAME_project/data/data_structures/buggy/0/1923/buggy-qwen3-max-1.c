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
    gets(s); // @@ [Using gets() is unsafe and may cause buffer overflow; also, the logic below has multiple flaws]
    for(i=0; i<strlen(s); i++){
        c='0';
        if(s[i] == '-'){
            if(s[i-1] >= 'A' && s[i-1] <= 'Z' && s[i+1] >= 'A' && s[i+1] <= 'Z'){
                c=s[i-1];
                while(c<s[i+1]-1){ // @@ [This condition stops one character too early; should be c < s[i+1]]
                    c=c+1;
                    printf("%c",c);
                }
            }
            if(s[i-1] >= 'a' && s[i-1] <= 'z' && s[i+1] >= 'a' && s[i+1] <= 'z'){ // @@ [This block runs even if previous condition was true, causing duplication or incorrect output]
                c=s[i-1];
                while(c<s[i+1]-1){ // @@ [Same off-by-one error: should expand up to s[i+1], not s[i+1]-1]
                    c=c+1;
                    printf("%c",c);
                }
            }
            if(s[i-1] >= '0' && s[i-1] <= '9' && s[i+1] >= '0' && s[i+1] <= '9'){ // @@ [Same issue: runs independently of prior conditions, and off-by-one error]
                c=s[i-1];
                while(c<s[i+1]-1){ // @@ [Should be c < s[i+1] to include the last character before s[i+1]]
                    c=c+1;
                    printf("%c",c);
                }
            }
            else{
                printf("-"); // @@ [This else only applies to the last if (digits), so '-' is printed even when letter ranges matched but didn't expand due to off-by-one]
            }
        }
        else(printf("%c",s[i])); // @@ [Missing space after 'else' is syntactically allowed but poor style; more importantly, when '-' is expanded, the original '-' is skipped, but surrounding characters are not handled correctly — e.g., 'a-u' prints expansion but doesn't skip the 'u', leading to duplication]
    }
    return 0;
}