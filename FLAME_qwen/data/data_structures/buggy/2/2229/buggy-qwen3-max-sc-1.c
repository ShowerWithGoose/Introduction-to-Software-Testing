#include<stdio.h>
int main(){
    char a[1000000];
    gets(a); // @@ [The function 'gets' is unsafe and has been removed from the C standard library since C11. It can cause buffer overflow and leads to undefined behavior. Most modern compilers (like GCC) will refuse to compile code using 'gets' unless explicitly allowed, which may result in a compilation error if the compiler does not recognize or support it.]
    puts(a);
    return 0;
}