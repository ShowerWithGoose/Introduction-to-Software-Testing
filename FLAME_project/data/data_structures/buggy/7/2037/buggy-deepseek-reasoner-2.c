#include <stdio.h>
int main (){
    char s[100];
    while (gets (s)!=NULL) { // @@ Incorrect input method: reads entire lines, but problem requires reading n then n integers. Also gets is unsafe.
        puts (s); // @@ Incorrect output: simply prints the line, should output leaf node values and heights.
    }
    return 0;
}