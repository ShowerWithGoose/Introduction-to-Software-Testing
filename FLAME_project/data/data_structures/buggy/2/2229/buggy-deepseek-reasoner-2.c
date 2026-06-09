#include<stdio.h>
int main(){
    char a[1000000];
    gets(a);
    puts(a); // @@ Error: This line outputs the raw input string instead of the computed result of the arithmetic expression. The program lacks the necessary logic to parse operators and operands, evaluate multiplication/division before addition/subtraction, and perform integer division.
    return 0;
}