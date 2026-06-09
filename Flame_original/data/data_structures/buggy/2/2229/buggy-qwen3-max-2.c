#include<stdio.h>
int main(){
    char a[1000000];
    gets(a); // @@ [The function 'gets' is unsafe and has been removed from the C standard library since C11. It can cause buffer overflow and leads to compilation errors or warnings on modern compilers. Use 'fgets' instead.]
    puts(a);
    return 0;
}