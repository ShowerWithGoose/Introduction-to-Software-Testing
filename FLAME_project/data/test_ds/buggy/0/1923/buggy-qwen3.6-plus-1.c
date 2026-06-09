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
    for(i=0; i<strlen(s); i++){ // @@ Accessing s[i-1] when i=0 causes out-of-bounds memory access; loop should start from i=1 or include boundary checks
        c='0';
        if(s[i] == '-'){
            if(s[i-1] >= 'A' && s[i-1] <= 'Z' && s[i+1] >= 'A' && s[i+1] <= 'Z'){ // @@ Missing condition s[i+1] > s[i-1] to ensure expansion only occurs when the second character is greater; subsequent 'if's should be 'else if'
                c=s[i-1];
                while(c<s[i+1]-1){
                    c=c+1;
                    printf("%c",c);
                }
            }
            if(s[i-1] >= 'a' && s[i-1] <= 'z' && s[i+1] >= 'a' && s[i+1] <= 'z'){ // @@ Should be 'else if' to prevent falling through to the final 'else' block and printing an extra '-'; also missing s[i+1] > s[i-1]
                c=s[i-1];
                while(c<s[i+1]-1){
                    c=c+1;
                    printf("%c",c);
                }
            }
            if(s[i-1] >= '0' && s[i-1] <= '9' && s[i+1] >= '0' && s[i+1] <= '9'){ // @@ Should be 'else if' to correctly associate with the following 'else' block; also missing s[i+1] > s[i-1]
                c=s[i-1];
                while(c<s[i+1]-1){
                    c=c+1;
                    printf("%c",c);
                }
            }
            else{
                printf("-");
            }
        }
        else(printf("%c",s[i]));
    }
    return 0;
}