#include <stdio.h>

int main(void){
    char p1[82]={0};
    char p2[82]={0};
    int move=0;
    gets(p1); // @@ [The program only reads input and prints it back without parsing or evaluating the arithmetic expression. It completely lacks implementation for handling operators, spaces, integer division, or calculation logic as required by the problem.]
    puts(p1); // @@ [This outputs the raw input instead of the computed result, which is why the output matches the input snippet "10 + 20 *..." rather than the expected integer 602.]
}