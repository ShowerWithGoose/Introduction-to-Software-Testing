#include <stdio.h>

int main(void){
    char p1[82]={0};
    char p2[82]={0};
    int move=0;
    gets(p1); // @@ gets() is removed in the C11 standard and causes compilation errors in modern compilers; use fgets(p1, sizeof(p1), stdin) instead.
    puts(p1);
}