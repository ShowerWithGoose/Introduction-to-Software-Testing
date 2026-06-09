#include <stdio.h>
#include <ctype.h>
int main() {
    char s[1145];
    scanf("%s",&s); // @@ [Passing &s (char (*)[1145]) to scanf with %s expects char*, but &s is a pointer to the whole array. Should pass s instead of &s.]
    if(s[0]=='a')
    {
        if(s[1]=='-')
        printf("abcdefghijklmnopqrstuBCDEF"); // @@ [Hardcoded output does not implement general expansion logic; violates problem requirements.]
        else printf("abcdefg0-A"); // @@ [Hardcoded output for non-expansion case is incorrect; should output original string.]
    }
    else  if(s[0]=='d')
        printf("dcu012345678"); // @@ [Hardcoded output does not follow expansion rules; fails to process input generically.]
    else  if(s[0]=='B')
        printf("B-e"); // @@ [Should output input unchanged if expansion conditions aren't met, but this hardcodes a specific string.]
    else  if(s[0]=='t')
        printf("toooold08A-a"); // @@ [Hardcoded output unrelated to input; violates requirement to output expanded or original string.]
    return 0;
}