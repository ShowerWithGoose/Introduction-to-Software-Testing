#include <stdio.h>

int main (){
    char s[100];
    while (gets (s)!=NULL) { // @@ The program logic is completely unrelated to the problem description. The problem requires constructing a Binary Search Tree (BST) from integer inputs and outputting leaf nodes with their heights. This code simply reads strings and echoes them, which explains the Wrong Answer.
        puts (s);
    }
    return 0;
}