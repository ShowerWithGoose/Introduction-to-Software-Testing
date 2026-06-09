#include<stdio.h>
int main(){
    char a[1000000];
    gets(a); // @@ [The function 'gets' is unsafe and has been removed from the C standard library since C11; many compilers (like GCC) no longer support it by default, leading to a compilation error. Use 'fgets' instead.]
    puts(a);
    return 0;
}