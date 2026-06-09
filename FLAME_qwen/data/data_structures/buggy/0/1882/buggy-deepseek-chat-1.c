#include <stdio.h>
#include <ctype.h>
int main() {
    char s[1145];
    scanf("%s",&s); // @@ [Error: scanf("%s", s) should be used instead of scanf("%s", &s) because s is already a pointer to the first element of the array; using &s passes the address of the array, which is technically the same address but of a different type, leading to undefined behavior or compiler warnings.]
    if(s[0]=='a')
    {
        if(s[1]=='-')
        printf("abcdefghijklmnopqrstuBCDEF"); // @@ [Error: This hardcoded output does not correctly implement the expansion logic described in the problem. It should dynamically expand the input string based on the characters around '-'.]
        else printf("abcdefg0-A"); // @@ [Error: This hardcoded output does not correctly implement the expansion logic described in the problem. It should dynamically expand the input string based on the characters around '-'.]
    }
    else  if(s[0]=='d')
        printf("dcu012345678"); // @@ [Error: This hardcoded output does not correctly implement the expansion logic described in the problem. It should dynamically expand the input string based on the characters around '-'.]
    else  if(s[0]=='B')
        printf("B-e"); // @@ [Error: This hardcoded output does not correctly implement the expansion logic described in the problem. It should dynamically expand the input string based on the characters around '-'.]
    else  if(s[0]=='t')
        printf("toooold08A-a"); // @@ [Error: This hardcoded output does not correctly implement the expansion logic described in the problem. It should dynamically expand the input string based on the characters around '-'.]
    return 0;
}