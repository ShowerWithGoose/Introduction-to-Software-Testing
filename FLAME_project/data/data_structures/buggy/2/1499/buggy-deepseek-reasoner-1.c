#include <stdio.h>

int main(void){
    char p1[82]={0};
    char p2[82]={0};
    int move=0;
    gets(p1);
    puts(p1); // @@ This line outputs the input string instead of computing and printing the result. The program should evaluate the arithmetic expression and print the integer result.
}