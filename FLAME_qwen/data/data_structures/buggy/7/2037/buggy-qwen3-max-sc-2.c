#include <stdio.h>

int main (){
    char s[100];
    while (gets (s)!=NULL) { // @@ [The `gets` function is unsafe and has been removed from the C standard library since C11; using it may cause compilation errors with modern compilers. Additionally, the problem requires constructing a BST and outputting leaf nodes with heights, but this code merely echoes input lines, indicating a complete logic mismatch.]
        puts (s);
    }
    return 0;
}