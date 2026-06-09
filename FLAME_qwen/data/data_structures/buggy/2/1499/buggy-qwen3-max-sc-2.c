#include <stdio.h>

int main(void){
    char p1[82]={0};
    char p2[82]={0};
    int move=0;
    gets(p1); // @@ [The function 'gets' is unsafe and has been removed from the C standard library since C11; many compilers (like GCC) no longer support it by default, leading to a compilation error. Use 'fgets' instead.]
    puts(p1);
}