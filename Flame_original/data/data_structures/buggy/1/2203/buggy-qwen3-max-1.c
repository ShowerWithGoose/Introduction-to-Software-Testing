#include<stdio.h>
#include<string.h>
int main(){
    char s[100];
    gets(s); // @@ [The function 'gets' is unsafe and has been removed from the C standard library since C11; many compilers no longer support it, leading to a compilation error.]
    printf("%s",s);
    return 0;
}