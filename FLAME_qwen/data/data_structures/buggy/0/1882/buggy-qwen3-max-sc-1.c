#include <stdio.h>
#include <ctype.h>
int main() {
    char s[1145];
    scanf("%s",&s); // @@ [Passing &s (char (*)[1145]) to scanf with %s expects char*, should be s instead of &s]
    if(s[0]=='a')
    {
        if(s[1]=='-')
        printf("abcdefghijklmnopqrstuBCDEF"); // @@ [Hardcoded output does not implement general expansion logic; violates problem requirements]
        else printf("abcdefg0-A"); // @@ [Hardcoded output for non-expansion case is incorrect; should output original string]
    }
    else  if(s[0]=='d')
        printf("dcu012345678"); // @@ [Hardcoded output does not reflect actual input or proper expansion logic]
    else  if(s[0]=='B')
        printf("B-e"); // @@ [Should output original string "B-e" only if no expansion applies, but this is hardcoded and doesn't handle general cases]
    else  if(s[0]=='t')
        printf("toooold08A-a"); // @@ [Hardcoded output unrelated to expansion logic; fails to process input correctly]
    return 0;
}