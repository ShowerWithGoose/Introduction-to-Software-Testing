#include <stdio.h>

int main (){
    char s[100];
    while (gets (s)!=NULL) { // @@ gets() is unsafe and removed from C11 standard; use fgets() instead
        puts (s);
    }
    return 0;
}