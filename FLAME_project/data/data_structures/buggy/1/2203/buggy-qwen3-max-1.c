#include<stdio.h>
#include<string.h>
int main(){
    char s[100];
    gets(s); // @@ [The program uses gets() to read input, but the problem expects an integer N. Also, gets() is unsafe and not suitable for reading integers. This causes the program to treat the input as a string instead of parsing it as an integer, leading to completely incorrect logic.]
    printf("%s",s); // @@ [The program simply prints the input string back, without generating any permutations. It does not implement permutation generation or lexicographical ordering as required by the problem.]
    return 0;
}