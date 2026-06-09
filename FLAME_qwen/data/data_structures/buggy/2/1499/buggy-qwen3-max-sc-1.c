#include <stdio.h>

int main(void){
    char p1[82]={0};
    char p2[82]={0};
    int move=0;
    gets(p1); // @@ [The `gets` function is unsafe and has been removed from the C standard library since C11 due to buffer overflow risks. Using `gets` can lead to undefined behavior and is likely causing a compilation error with modern compilers that do not support it by default.]
    puts(p1);
}