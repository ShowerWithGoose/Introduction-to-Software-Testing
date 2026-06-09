#include<stdio.h>
int main(){
    char a[1000000];
    gets(a); // @@ The program uses gets() which is unsafe and may cause buffer overflow, but more importantly, it does not evaluate the arithmetic expression. It simply reads and prints the input, which does not solve the problem.
    puts(a); // @@ This line prints the input string instead of computing and outputting the result of the arithmetic expression.
    return 0;
}