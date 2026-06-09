#include <stdio.h>

int main (){
    char s[100];
    while (gets (s)!=NULL) { // @@ 'gets' is removed in C11 standard causing compilation errors; also fails to parse integers or construct BST.
        puts (s); // @@ Logic is completely missing; should construct BST and output leaf nodes with heights, not echo input.
    }
    return 0;
}