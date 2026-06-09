#include <stdio.h>
#include <ctype.h>
int main() {
    char s[1145];
    scanf("%s",&s); // @@ This line reads a string but only the first character is ever used to decide the output, ignoring the expansion logic.
    if(s[0]=='a') // @@ This condition checks only the first character, not the full input string; it is too specific and does not implement the required expansion.
    {
        if(s[1]=='-') // @@ This condition is also too specific; it only checks if the second character is '-', but does not process the rest of the string correctly.
        printf("abcdefghijklmnopqrstuBCDEF"); // @@ This is a hardcoded output for a specific input, not the actual expansion result. For input "a-c-g0-A" it incorrectly outputs this string instead of "abcdefg0-A".
        else printf("abcdefg0-A"); // @@ Another hardcoded output; the program should deduce the correct expanded string dynamically.
    }
    else  if(s[0]=='d')
        printf("dcu012345678"); // @@ Hardcoded output, no expansion logic.
    else  if(s[0]=='B')
        printf("B-e"); // @@ Hardcoded output, no expansion logic.
    else  if(s[0]=='t')
        printf("toooold08A-a"); // @@ Hardcoded output, no expansion logic.
    return 0;
}