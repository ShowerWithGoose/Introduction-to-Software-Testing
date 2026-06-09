#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
int main(){
    char s[100000];
    int j=0;
    gets(s);
    int l=strlen(s);
    printf("%c",s[0]);
    for(int i=1;i<l;i++){
        if(s[i]=='-'){
            if(s[i-1]>=48&&s[i-1]<=57&&s[i+1]>=48&&s[i+1]<=57&&s[i-1]<s[i+1])
            {
                for(j=s[i-1];j<s[i+1];j++)
                printf("%c",j+1);
                i++;
            }
            if(s[i-1]>=65&&s[i-1]<=90&&s[i+1]>=65&&s[i+1]<=90&&s[i-1]<s[i+1])
            {
                for(j=s[i-1];j<s[i+1];j++)
                printf("%c",j+1);
                i++; @@ [After expanding, 'i' is incremented, but if multiple conditions are checked (e.g., digit and uppercase both false, then lowercase true), 'i' may be incremented multiple times or the '-' may be printed additionally due to missing 'else if'. Also, after incrementing 'i', the next character (after '-') is skipped in the loop, but if none of the conditions match, the else clause prints '-', yet the structure allows fall-through.]
            }
            if(s[i-1]>=97&&s[i-1]<=122&&s[i+1]>=97&&s[i+1]<=122&&s[i-1]<s[i+1])
            {
                for(j=s[i-1];j<s[i+1];j++)
                printf("%c",j+1);
                i++; @@ [Same issue: using separate 'if's instead of 'else if' causes potential double expansion or incorrect control flow. Also, after incrementing 'i', the loop will skip the next character, but if this block executes, the following 'else' should not run — however, because it's a separate 'if', the final 'else' may still execute if the last condition fails, leading to duplicate output.]
            }
            else printf("%c",s[i]); @@ [This 'else' only pairs with the last 'if', not the whole group. So if the first or second 'if' matches and runs, this 'else' is still evaluated against the third 'if', possibly printing an extra '-'. This causes duplication like the extra 'F' in the output.]
        }
        else{
            printf("%c",s[i]);
        }
    }
    return 0;
}