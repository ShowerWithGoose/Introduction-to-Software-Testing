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
        if(s[i] == '-'){ // @@ No boundary check: should handle dashes at first or last position (i==0 or i==strlen(s)-1) without expansion; otherwise may access invalid memory.
            if(s[i-1] >= 'A' && s[i-1] <= 'Z' && s[i+1] >= 'A' && s[i+1] <= 'Z'){ // @@ Missing condition: s[i+1] > s[i-1] is required before expansion.
                c=s[i-1];
                while(c<s[i+1]-1){
                    c=c+1;
                    printf("%c",c);
                }
            }
            if(s[i-1] >= 'a' && s[i-1] <= 'z' && s[i+1] >= 'a' && s[i+1] <= 'z'){ // @@ Missing condition: s[i+1] > s[i-1] is required before expansion.
                c=s[i-1];
                while(c<s[i+1]-1){
                    c=c+1;
                    printf("%c",c);
                }
            }
            if(s[i-1] >= '0' && s[i-1] <= '9' && s[i+1] >= '0' && s[i+1] <= '9'){ // @@ Missing condition: s[i+1] > s[i-1] is required before expansion.
                c=s[i-1];
                while(c<s[i+1]-1){
                    c=c+1;
                    printf("%c",c);
                }
            }
            else{ // @@ The else is attached only to the third if, causing a dash to be printed even when a previous if (lowercase/uppercase) executed expansion. It should be an overall else for all three type checks.
                printf("-");
            }
        }
        else(printf("%c",s[i]));
    }
    return 0;
}