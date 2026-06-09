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
    gets(s); @@ [Using gets() is unsafe and may cause buffer overflow; also, the logic fails to handle cases where '-' appears at the start or end of string]
    for(i=0; i<strlen(s); i++){
        c='0';
        if(s[i] == '-'){
            if(s[i-1] >= 'A' && s[i-1] <= 'Z' && s[i+1] >= 'A' && s[i+1] <= 'Z'){
                c=s[i-1];
                while(c<s[i+1]-1){ @@ [Loop condition should be c < s[i+1], not c < s[i+1]-1, because we need to include the character just before s[i+1]]
                    c=c+1;
                    printf("%c",c);
                }
            }
            if(s[i-1] >= 'a' && s[i-1] <= 'z' && s[i+1] >= 'a' && s[i+1] <= 'z'){
                c=s[i-1];
                while(c<s[i+1]-1){ @@ [Same error: should print up to s[i+1]-1 inclusive, so condition should be c < s[i+1]]
                    c=c+1;
                    printf("%c",c);
                }
            }
            if(s[i-1] >= '0' && s[i-1] <= '9' && s[i+1] >= '0' && s[i+1] <= '9'){
                c=s[i-1];
                while(c<s[i+1]-1){ @@ [Same off-by-one error in loop condition]
                    c=c+1;
                    printf("%c",c);
                }
            }
            else{
                printf("-"); @@ [This else only applies to the last if (digits), not all three conditions; so if any of the first two ifs match but the third doesn't, it still prints '-', causing duplication]
            }
        }
        else(printf("%c",s[i])); @@ [This prints non-'-' characters, but when expansion happens, the original '-' and surrounding chars are not properly skipped, leading to duplicated or missing characters]
    }
    return 0;
}