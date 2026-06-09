#include<stdio.h>
int main(){
    char a[1000000];
    gets(a); // @@ [The function 'gets' is unsafe and has been removed from the C standard library since C11. It can cause buffer overflow and is not allowed in secure code. Most modern compilers (like GCC) will issue a compilation error or warning when 'gets' is used, which explains the "gcc: not found" error message—this is likely a misleading shell error due to compilation failure.]
    puts(a);
    return 0;
}