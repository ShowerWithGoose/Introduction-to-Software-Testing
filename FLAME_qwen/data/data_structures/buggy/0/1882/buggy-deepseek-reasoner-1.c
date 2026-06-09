#include <stdio.h>
#include <ctype.h>
int main() {
    char s[1145];
    scanf("%s",&s); // @@ [Incorrect: '&s' is the address of the entire array, not a pointer to char. Should be 'scanf("%s", s);'. This may cause undefined behavior or compilation warnings.]
    if(s[0]=='a')
    {
        if(s[1]=='-')
        printf("abcdefghijklmnopqrstuBCDEF"); // @@ [Error: Hardcoded output does not implement the required expansion algorithm. The program should process any input string following the specification, not just specific test cases.]
        else printf("abcdefg0-A"); // @@ [Error: Same as above - hardcoded output for a specific case, no general expansion logic.]
    }
    else  if(s[0]=='d')
        printf("dcu012345678"); // @@ [Error: Hardcoded output, not a general solution.]
    else  if(s[0]=='B')
        printf("B-e"); // @@ [Error: Hardcoded output, does not handle general input.]
    else  if(s[0]=='t')
        printf("toooold08A-a"); // @@ [Error: Hardcoded output, no expansion logic.]
    return 0;
}