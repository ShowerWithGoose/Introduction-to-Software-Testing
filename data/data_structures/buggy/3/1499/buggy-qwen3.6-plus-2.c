#include <stdio.h>

int main(void){
    char p1[82]={0};
    char p2[82]={0};
    int move=0;
    gets(p1); // @@ gets() has been removed from the C11 standard and causes a compilation error in modern compilers; use fgets() instead.
    puts(p1);
}