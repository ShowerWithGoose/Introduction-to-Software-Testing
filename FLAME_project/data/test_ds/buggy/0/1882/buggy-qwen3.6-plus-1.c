#include <stdio.h>
#include <ctype.h>
int main() {
    char s[1145];
    scanf("%s",&s);
    if(s[0]=='a') // @@ Hardcoded condition instead of dynamically iterating through the string to apply expansion rules.
    {
        if(s[1]=='-') // @@ Hardcoded check that does not handle general cases or multiple expansion symbols.
        printf("abcdefghijklmnopqrstuBCDEF"); // @@ Hardcoded output that incorrectly expands the string and violates the problem's type-matching and ordering constraints.
        else printf("abcdefg0-A"); // @@ Hardcoded output for a specific case, failing to implement the required algorithm.
    }
    else  if(s[0]=='d') // @@ Hardcoded condition.
        printf("dcu012345678"); // @@ Hardcoded output.
    else  if(s[0]=='B') // @@ Hardcoded condition.
        printf("B-e"); // @@ Hardcoded output.
    else  if(s[0]=='t') // @@ Hardcoded condition.
        printf("toooold08A-a"); // @@ Hardcoded output.
    return 0;
}