#include <stdio.h>

int main(void){
    char p1[82]={0};
    char p2[82]={0};
    int move=0;
    gets(p1);
    puts(p1); // @@ This line outputs the input as-is without converting to scientific notation. The program should process the input and output the scientific notation format, not just echo the input.
}