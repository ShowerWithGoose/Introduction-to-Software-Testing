#include<stdio.h>
int main(){
    char s[1005];
    int i=9900;
    while(i--){
    gets(s)    ; // @@ [The function 'gets' is unsafe and has been removed from the C standard library since C11; many compilers (like GCC) no longer support it by default, leading to a compilation error. Use 'fgets' instead.]
    puts(s);//TODO
    }return 0;
}