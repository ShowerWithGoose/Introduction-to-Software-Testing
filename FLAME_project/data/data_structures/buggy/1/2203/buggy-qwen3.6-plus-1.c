#include<stdio.h>
#include<string.h>
int main(){
    char s[100];
    gets(s); // @@ The problem requires generating permutations of integers from 1 to N, but this code simply reads a string and prints it. It does not implement the permutation logic at all.
    printf("%s",s); // @@ This line prints the input string directly, which is incorrect. The expected output for input "2" is "1 2 ", not "2".
    return 0;
}