#include <stdio.h>

int main(void){
    char p1[82]={0};
    char p2[82]={0};
    int move=0;
    gets(p1); // @@ [The function 'gets' is unsafe and has been removed from the C standard library since C11; using it can lead to buffer overflow vulnerabilities and may cause compilation errors with modern compilers that do not support it.]
    puts(p1);
}