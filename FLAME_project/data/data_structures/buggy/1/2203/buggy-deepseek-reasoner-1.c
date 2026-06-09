#include<stdio.h>
#include<string.h>
int main(){
    char s[100];
    gets(s); // @@ [Error: should read an integer N using scanf, not a string. The program must generate permutations of 1..N, not just echo input.]
    printf("%s",s); // @@ [Error: outputs the input string, but the program should print all permutations of 1..N in lexicographic order.]
    return 0;
}