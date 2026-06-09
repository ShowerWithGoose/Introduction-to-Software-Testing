#include <stdio.h>

int main(void){
    char p1[82]={0};
    char p2[82]={0};
    int move=0;
    gets(p1); // @@ gets() is removed in the C11 standard and causes a compilation error in modern compilers; it should be replaced with fgets().
    puts(p1);
}