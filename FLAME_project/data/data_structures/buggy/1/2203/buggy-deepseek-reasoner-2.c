#include<stdio.h>
#include<string.h>
int main(){
    char s[100];
    gets(s); // @@ [Error: The program should read an integer N, not a string. This line reads the input as a string, but the problem requires reading an integer to generate all permutations of numbers 1 to N.]
    printf("%s",s); // @@ [Error: This line prints the input string. The program is supposed to output all N! permutations in lexicographic order, each on a new line, with numbers separated by spaces. The entire permutation generation logic is missing.]
    return 0;
}