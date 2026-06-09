#include <stdio.h>
#include <ctype.h>
int main() {
    char s[1145];
    scanf("%s",&s); // @@ Incorrect argument type for scanf: '&s' passes the address of the array, but scanf expects a char pointer. It should be 's'.
    if(s[0]=='a') // @@ The logic is hardcoded for specific test cases instead of implementing the general string expansion algorithm required by the problem description.
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