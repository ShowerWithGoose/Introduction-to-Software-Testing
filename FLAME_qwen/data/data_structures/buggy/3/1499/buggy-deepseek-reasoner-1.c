#include <stdio.h>

int main(void){
    char p1[82]={0};
    char p2[82]={0};
    int move=0;
    gets(p1); // @@ [gets() is removed from the C11 standard, causing a compilation error when using strict C11/C17 mode]
    puts(p1);
}