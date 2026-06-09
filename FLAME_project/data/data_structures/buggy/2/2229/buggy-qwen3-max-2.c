#include<stdio.h>
int main(){
    char a[1000000];
    gets(a); // @@ [The program reads the input but does not parse or evaluate the arithmetic expression; it simply outputs the raw input string.]
    puts(a); // @@ [This outputs the entire input expression as-is instead of computing and outputting the result of the arithmetic expression.]
    return 0;
}