#include <stdio.h>

int main(void){
    char p1[82]={0};
    char p2[82]={0};
    int move=0;
    gets(p1);
    puts(p1); @@ // Error: This line prints the input string instead of computing and outputting the result of the arithmetic expression.
}