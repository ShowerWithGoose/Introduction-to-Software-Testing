#include<stdio.h>
int main(){
    char a[1000000];
    gets(a); // @@ The program simply reads the input and prints it back out, instead of parsing and evaluating the arithmetic expression as required by the problem description.
    puts(a); // @@ This line outputs the raw input string rather than the calculated integer result.
    return 0;
}