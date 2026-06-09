#include<stdio.h>
int main(){
    char a[1000000];
    gets(a); // @@ This line reads the entire input including spaces, but the program does not evaluate the expression; it only prints the input back. The problem requires computing the arithmetic expression.
    puts(a); // @@ This line outputs the input string instead of computing and printing the result of the expression.
    return 0;
}