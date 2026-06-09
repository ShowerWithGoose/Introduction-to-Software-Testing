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
                i++; @@ [After expanding, 'i' is incremented, but if multiple conditions are checked (e.g., digit and uppercase both false but lowercase true), 'i' may be incremented multiple times or incorrectly. Also, using separate 'if's instead of 'else if' causes fall-through behavior leading to duplicate output like extra 'F'.]
            }
            if(s[i-1]>=97&&s[i-1]<=122&&s[i+1]>=97&&s[i+1]<=122&&s[i-1]<s[i+1])
            {
                for(j=s[i-1];j<s[i+1];j++)
                printf("%c",j+1);
                i++; @@ [Same issue: multiple 'if's can cause 'i' to be incremented more than once when only one expansion should occur. This leads to skipping characters or double processing.]
            }
            else printf("%c",s[i]); @@ [This 'else' only pairs with the last 'if', so if any prior 'if' condition is true, this 'else' is skipped even if later conditions fail. This causes '-' to be printed unnecessarily in some cases, but more critically, due to lack of mutual exclusion among the three type checks, the logic is flawed.]
        }
        else{
            printf("%c",s[i]);
        }
    }
    return 0;
}