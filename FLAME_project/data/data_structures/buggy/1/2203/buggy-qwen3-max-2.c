#include<stdio.h>
#include<string.h>
int main(){
    char s[100];
    gets(s); // @@ [The program uses gets() to read input, but the problem expects an integer N. Also, gets() is unsafe and doesn't parse integer input correctly for this problem.]
    printf("%s",s); // @@ [The program outputs the raw string input instead of generating and printing all lexicographically sorted permutations of numbers 1 to N.]
    return 0;
}