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
    for(i=0; i<strlen(s); i++){ // @@ missing bounds check for s[i-1] and s[i+1] when i==0 or i==strlen(s)-1
        c='0';
        if(s[i] == '-'){
            if(s[i-1] >= 'A' && s[i-1] <= 'Z' && s[i+1] >= 'A' && s[i+1] <= 'Z'){ // @@ missing condition s[i+1] > s[i-1]; also should be part of if-else if chain
                c=s[i-1];
                while(c<s[i+1]-1){
                    c=c+1;
                    printf("%c",c);
                }
            }
            if(s[i-1] >= 'a' && s[i-1] <= 'z' && s[i+1] >= 'a' && s[i+1] <= 'z'){ // @@ missing condition s[i+1] > s[i-1]; should be else if
                c=s[i-1];
                while(c<s[i+1]-1){
                    c=c+1;
                    printf("%c",c);
                }
            }
            if(s[i-1] >= '0' && s[i-1] <= '9' && s[i+1] >= '0' && s[i+1] <= '9'){ // @@ missing condition s[i+1] > s[i-1]; should be else if
                c=s[i-1];
                while(c<s[i+1]-1){
                    c=c+1;
                    printf("%c",c);
                }
            }
            else{ // @@ else incorrectly attached to the third if only; should be part of unified if-else if-else structure
                printf("-");
            }
        }
        else(printf("%c",s[i]));
    }
    return 0;
}