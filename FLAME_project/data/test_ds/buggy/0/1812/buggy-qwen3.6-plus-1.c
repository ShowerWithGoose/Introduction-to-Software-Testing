#include <stdio.h>
#include <string.h>
#include <ctype.h>
char s[501];
int main() {
    scanf("%s", s);
    for (int i = 0; s[i]!='\0'; i++) { // @@ The loop automatically increments i after processing '-', which skips the first inserted character. i should be decremented after the insertion block.
        if (s[i] >= 'a' &&