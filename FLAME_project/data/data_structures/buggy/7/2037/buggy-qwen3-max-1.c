#include <stdio.h>

int main (){
    char s[100];
    while (gets (s)!=NULL) {
        puts (s);
    }
    return 0;
} // @@ [The entire program is unrelated to the problem description. It reads lines and prints them, but the problem requires building a BST from integers and printing leaf nodes with their heights. The provided source code does not implement any BST logic, nor does it read the input format specified (an integer n followed by n integers). This explains the wrong answer: for input "1\n5678", it treats "1" as a string line and outputs "1", then treats "5678" as another line and outputs "5678", resulting in two lines of output instead of the expected single line "5678 1".]