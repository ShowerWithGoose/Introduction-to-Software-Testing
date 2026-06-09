#include <stdio.h>
#include <ctype.h>
int main() {
    char s[1145];
    scanf("%s",&s);
    if(s[0]=='a')
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
