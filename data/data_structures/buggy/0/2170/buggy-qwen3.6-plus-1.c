#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
int main(){
    char s[100000];
    int j=0;
    gets(s); // @@ 'gets' is removed in the C11 standard and causes compilation errors in modern compilers; use 'fgets' or 'scanf' instead.
    int l=strlen(s);
    printf("%c",s[0]);
    for(int i=1;i<l;i++){
        if(s[i]=='-'){
            if(s[i-1]>=48&&s[i-1]<=57&&s[i+1]>=48&&s[i+1]<=57&&s[i-1]<s[i+1])
            {
                for(j=s[i-1];j<s[i+1];j++)
                printf("%c",j+1);
                i++; // @@ Unnecessary increment; the for loop already increments i, causing the next character to be skipped or leading to out-of-bounds access.
            }
            if(s[i-1]>=65&&s[i-1]<=90&&s[i+1]>=65&&s[i+1]<=90&&s[i-1]<s[i+1]) // @@ Should be 'else if' to form a proper conditional chain; otherwise, the 'else' on line 31 only pairs with this block's condition.
            {
                for(j=s[i-1];j<s[i+1];j++)
                printf("%c",j+1);
                i++; // @@ Unnecessary increment; the for loop already increments i, causing the next character to be skipped or leading to out-of-bounds access.
            }
            if(s[i-1]>=97&&s[i-1]<=122&&s[i+1]>=97&&s[i+1]<=122&&s[i-1]<s[i+1]) // @@ Should be 'else if' to correctly chain the conditions.
            {
                for(j=s[i-1];j<s[i+1];j++)
                printf("%c",j+1);
                i++; // @@ Unnecessary increment; the for loop already increments i, causing the next character to be skipped or leading to out-of-bounds access.
            }
            else printf("%c",s[i]); // @@ Due to missing 'else if' above, this 'else' incorrectly executes when digit or uppercase expansion occurs, redundantly printing '-'.
        }
        else{
            printf("%c",s[i]);
        }
    }
    return 0;
}