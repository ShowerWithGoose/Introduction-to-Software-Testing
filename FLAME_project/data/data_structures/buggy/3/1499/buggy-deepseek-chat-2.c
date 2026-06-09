#include <stdio.h>

int main(void){
    char p1[82]={0};
    char p2[82]={0};
    int move=0;
    gets(p1);
    puts(p1); // @@ This line outputs the original input without any conversion to scientific notation. The program should parse the input and output the scientific notation format as specified in the problem description.
}