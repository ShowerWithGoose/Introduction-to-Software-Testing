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
    gets(s); // @@ [Using gets() is unsafe and may cause buffer overflow; also, the logic below fails to handle boundary conditions like '-' at start/end]
    for(i=0; i<strlen(s); i++){
        c='0';
        if(s[i] == '-'){
            if(s[i-1] >= 'A' && s[i-1] <= 'Z' && s[i+1] >= 'A' && s[i+1] <= 'Z'){
                c=s[i-1];
                while(c<s[i+1]-1){ // @@ [Loop condition should be c < s[i+1], not c < s[i+1]-1; this skips the last character in expansion]
                    c=c+1;
                    printf("%c",c);
                }
            }
            if(s[i-1] >= 'a' && s[i-1] <= 'z' && s[i+1] >= 'a' && s[i+1] <= 'z'){
                c=s[i-1];
                while(c<s[i+1]-1){ // @@ [Same error: should expand up to s[i+1], not s[i+1]-1]
                    c=c+1;
                    printf("%c",c);
                }
            }
            if(s[i-1] >= '0' && s[i-1] <= '9' && s[i+1] >= '0' && s[i+1] <= '9'){
                c=s[i-1];
                while(c<s[i+1]-1){ // @@ [Same off-by-one error in digit expansion]
                    c=c+1;
                    printf("%c",c);
                }
            }
            else{
                printf("-"); // @@ [This else only pairs with the last if (digits), so if '-' is between letters, it won't print '-' when it should (e.g., mixed types)]
            }
        }
        else(printf("%c",s[i])); // @@ [Missing space after 'else' is syntactically okay but unusual; more importantly, no handling for cases where '-' is at index 0 or last index, leading to out-of-bounds access]
    }
    return 0;
}