#include <stdio.h>
#include <ctype.h>
int main() {
    char s[1145];
    scanf("%s",&s); // @@ [Error: scanf("%s", s) should be used instead of scanf("%s", &s) because s is already an array name that decays to a pointer; using &s is incorrect and may cause undefined behavior]
    if(s[0]=='a')
    {
        if(s[1]=='-')
        printf("abcdefghijklmnopqrstuBCDEF"); // @@ [Error: This does not implement the required expansion logic; it hardcodes a specific output instead of processing the input string according to the problem description]
        else printf("abcdefg0-A"); // @@ [Error: This hardcodes a specific output instead of implementing the general expansion algorithm]
    }
    else  if(s[0]=='d')
        printf("dcu012345678"); // @@ [Error: Hardcoded output, not implementing the expansion logic]
    else  if(s[0]=='B')
        printf("B-e"); // @@ [Error: Hardcoded output, not implementing the expansion logic]
    else  if(s[0]=='t')
        printf("toooold08A-a"); // @@ [Error: Hardcoded output, not implementing the expansion logic]
    return 0;
}