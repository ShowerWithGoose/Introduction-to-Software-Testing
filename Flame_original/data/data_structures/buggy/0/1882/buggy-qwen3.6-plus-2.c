#include <stdio.h>
#include <ctype.h>
int main() {
    char s[1145];
    scanf("%s",&s); // @@ Type mismatch: '&s' is a pointer to an array, but scanf expects a 'char *'. This causes a compilation warning/error.
    if(s[0]=='a') // @@ Logical error: The program uses hardcoded conditional checks and outputs instead of implementing the general string expansion algorithm required by the problem description.
    {
        if(s[1]=='-')
        printf("abcdefghijklmnopqrstuBCDEF");
        else printf("abcdefg0-A");
    }
    else  if(s[0]=='d')
        printf("dcu012345678");
    else  if(s[0]=='B')
        printf("B-e");
    else  if(s[0]=='t')
        printf("toooold08A-a");
    return 0;
}