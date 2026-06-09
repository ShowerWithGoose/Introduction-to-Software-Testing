#include <stdio.h>
#include <ctype.h>
int main() {
    char s[1145];
    scanf("%s",&s); // @@ Error: scanf expects a pointer to char array, not pointer to array; use s instead of &s.
    if(s[0]=='a') // @@ Error: Program should handle all inputs based on expansion rules, not just those starting with specific characters; logic is incomplete.
    {
        if(s[1]=='-') // @@ Error: The expansion logic is not implemented; instead, hardcoded output is used.
        printf("abcdefghijklmnopqrstuBCDEF"); // @@ Error: Hardcoded output does not perform expansion as required.
        else printf("abcdefg0-A"); // @@ Error: Hardcoded output.
    }
    else  if(s[0]=='d') // @@ Error: Only handles a specific input, does not implement general expansion.
        printf("dcu012345678"); // @@ Error: Hardcoded output.
    else  if(s[0]=='B') // @@ Error: Only handles a specific input.
        printf("B-e"); // @@ Error: Hardcoded output.
    else  if(s[0]=='t') // @@ Error: Only handles a specific input.
        printf("toooold08A-a"); // @@ Error: Hardcoded output.
    return 0;
}