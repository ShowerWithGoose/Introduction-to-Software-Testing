#include<stdio.h>
int main(){
    char s[1005];
    int i=9900;
    while(i--){
    gets(s)    ; // @@ [The function 'gets' is unsafe and has been removed from the C standard library since C11; using it may cause compilation errors or warnings in modern compilers. Additionally, the program logic does not implement DFS/BFS traversals as required by the problem description—it merely echoes input lines, which is completely incorrect behavior.]
    puts(s);//TODO
    }return 0;
}