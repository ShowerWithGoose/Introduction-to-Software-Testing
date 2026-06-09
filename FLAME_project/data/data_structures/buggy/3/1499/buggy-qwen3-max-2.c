#include <stdio.h>

int main(void){
    char p1[82]={0};
    char p2[82]={0};
    int move=0;
    gets(p1); // @@ [The program reads input but does nothing to process it into scientific notation; it just prints the input back.]
    puts(p1); // @@ [This outputs the original input unchanged, which is why "0.9" is printed instead of "9e-1".]
}