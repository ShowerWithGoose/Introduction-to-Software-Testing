#include <stdio.h>

int main(void){
    char p1[82]={0};
    char p2[82]={0};
    int move=0;
    gets(p1); // @@ [The program only reads input and prints it back without parsing or evaluating the arithmetic expression. It completely lacks implementation for processing operators, handling spaces, performing calculations with operator precedence (* and / before + and -), and integer division as required.]
    puts(p1); // @@ [This outputs the raw input instead of the computed result, which is why the output matches the input prefix rather than the expected numeric answer like 602.]
}