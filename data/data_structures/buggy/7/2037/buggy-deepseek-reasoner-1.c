#include <stdio.h>

int main (){
    char s[100];
    while (gets (s)!=NULL) { // @@ [Compilation Error: 'gets' is removed in C11 and is unsafe; also the program does not construct BST as required by the problem.]
        puts (s);
    }
    return 0;
}