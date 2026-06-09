#include <stdio.h>
#include <stdlib.h>
#include <string.h>
char s[10086];
int main()
{
    fgets(s,10086,stdin);
    for(int i=0;s[i]!='\n';i++) // @@ The loop condition checks for '\n', but the input string may not end with a newline character (e.g., when reading from a file or pipe without a trailing newline). This causes