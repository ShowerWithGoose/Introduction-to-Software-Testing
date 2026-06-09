#include<stdio.h>
int main(){
    char s[1005];
    int i=9900;
    while(i--){
    gets(s)    ; // @@ [The function 'gets' is unsafe and has been removed from the C standard library since C11; using it may cause compilation errors or warnings in modern compilers. Additionally, the loop reads input far more times than needed, which is logically incorrect for the problem.]
    puts(s);//TODO
    }return 0;
}