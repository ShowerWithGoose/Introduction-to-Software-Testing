#include<stdio.h>
int main() {
    int n;
    while (scanf("%d", &n)==1) { // @@ This loop does not implement stack operations; it reads all integers without distinguishing between commands and values.
        printf("%d ", n); // @@ This prints every input integer, instead of only elements popped from the stack.
    }
    return 0;
}