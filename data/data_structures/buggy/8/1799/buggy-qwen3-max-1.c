#include<stdio.h>
int main(){
    char s[1005];
    int i=9900;
    while(i--){
    gets(s)    ; // @@ [The function 'gets' is unsafe and has been removed from the C standard library since C11; its use can lead to buffer overflow vulnerabilities. Additionally, in many modern compilers/environments, 'gets' is not available, which causes a compilation error.]
    puts(s);//TODO
    }return 0;
}