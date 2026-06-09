#include<stdio.h>
int main(){
    char a[1000000];
    gets(a);
    puts(a); // @@ Error: This line prints the input expression instead of computing and outputting the result. The program lacks logic to evaluate the arithmetic expression.
    return 0;
}