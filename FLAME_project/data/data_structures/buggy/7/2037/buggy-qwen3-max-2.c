#include <stdio.h>

int main (){
    char s[100];
    while (gets (s)!=NULL) {
        puts (s);
    }
    return 0;
} // @@ [The program completely ignores the problem requirements: it does not read an integer n, does not read n integers, does not build a BST, and does not output leaf nodes with their heights. Instead, it reads lines as strings and echoes them, which is unrelated to the task.]