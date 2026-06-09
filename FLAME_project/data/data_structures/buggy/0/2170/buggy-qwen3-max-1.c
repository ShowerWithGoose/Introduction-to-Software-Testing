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
                i++; @@ [Same issue: multiple 'if's cause potential double increment of 'i' and incorrect control flow. In test case "a-uB-F", after processing 'u'-'B' (which shouldn't expand), it incorrectly processes 'B'-'F' but due to flawed logic, the final 'F' is printed twice.]
            }
            else printf("%c",s[i]); @@ [This 'else' only pairs with the last 'if', so if any prior 'if' condition fails but the last one also fails, '-' is printed. However, if any earlier 'if' succeeds, expansion happens AND then this 'else' is skipped, but due to multiple 'if's, logic is broken. Should use 'else if' chain and handle non-expansion case properly.]
        }
        else{
            printf("%c",s[i]);
        }
    }
    return 0;
}