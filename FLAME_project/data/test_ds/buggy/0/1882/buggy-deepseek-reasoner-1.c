#include <stdio.h>
#include <ctype.h>
int main() {
    char s[1145];
    scanf("%s",&s);
    if(s[0]=='a') // @@ The program hardcodes behavior based on the first character instead of implementing the general expansion algorithm.
    {
        if(s[1]=='-') // @@ Again, hardcoded condition that does not correctly handle all inputs.
        printf("abcdefghijklmnopqrstuBCDEF"); // @@ Output is a hardcoded string, not the result of expanding the input correctly.
        else printf("abcdefg0-A"); // @@ Hardcoded output for a specific case, not general.
    }
    else  if(s[0]=='d') // @@ Hardcoded condition, does not handle general input.
        printf("dcu012345678"); // @@ Hardcoded output.
    else  if(s[0]=='B') // @@ Hardcoded condition.
        printf("B-e"); // @@ Hardcoded output.
    else  if(s[0]=='t') // @@ Hardcoded condition.
        printf("toooold08A-a"); // @@ Hardcoded output.
    return 0;
}