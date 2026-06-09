#include <stdio.h>

int main(void){
    char p1[82]={0};
    char p2[82]={0};
    int move=0;
    gets(p1);
    puts(p1); // @@ The program simply echoes the input instead of converting it to scientific notation. It lacks the logic to parse the decimal number, determine the exponent, and format the output as required (e.g., for "0.9", it should output "9e-1").
}