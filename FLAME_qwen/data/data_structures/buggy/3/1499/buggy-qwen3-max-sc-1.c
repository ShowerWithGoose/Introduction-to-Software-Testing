#include <stdio.h>

int main(void){
    char p1[82]={0};
    char p2[82]={0};
    int move=0;
    gets(p1); // @@ [The function 'gets' is unsafe and has been removed from the C standard library since C11; using it may cause compilation errors or warnings depending on compiler settings. Additionally, the program does not implement the required scientific notation conversion logic at all.]
    puts(p1); // @@ [This simply echoes the input instead of converting it to scientific notation, which violates the problem requirements.]
}