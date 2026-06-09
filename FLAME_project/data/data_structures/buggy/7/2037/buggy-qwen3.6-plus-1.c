#include <stdio.h>

int main (){
    char s[100];
    while (gets (s)!=NULL) { // @@ The program logic is completely unrelated to the problem description (BST construction and traversal). It simply echoes input lines. The expected output requires building a BST, finding leaf nodes, and printing their values and heights. This code fails to implement any of the required functionality.
        puts (s);
    }
    return 0;
}