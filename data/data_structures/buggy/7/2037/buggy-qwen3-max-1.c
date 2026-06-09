#include <stdio.h>

int main (){
    char s[100];
    while (gets (s)!=NULL) { // @@ [The `gets` function is unsafe and has been removed from the C standard library since C11, leading to compilation errors on modern compilers. It should be replaced with `fgets`.]
        puts (s);
    }
    return 0;
}