#include<stdio.h>
int main(){
    char s[1005];
    int i=9900;
    while(i--){
    gets(s)    ; // @@ [The function 'gets' is unsafe and has been removed from the C standard library since C11; many modern compilers (like GCC) no longer support it by default, leading to a compilation error. Additionally, the program logic using 'gets' in a loop with arbitrary iterations does not match the problem requirements.]
    puts(s);//TODO
    }return 0;
}