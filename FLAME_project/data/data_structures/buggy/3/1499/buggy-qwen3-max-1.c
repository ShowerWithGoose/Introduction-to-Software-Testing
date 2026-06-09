#include <stdio.h>

int main(void){
    char p1[82]={0};
    char p2[82]={0};
    int move=0;
    gets(p1); // @@ [The program reads input but does nothing to process it into scientific notation. It simply outputs the input as-is using puts(), which is why "0.9" is printed instead of "9e-1".]
    puts(p1); // @@ [This directly prints the input string without any conversion to scientific notation, leading to wrong output.]
}