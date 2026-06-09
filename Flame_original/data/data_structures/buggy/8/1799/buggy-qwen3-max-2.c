#include<stdio.h>
int main(){
    char s[1005];
    int i=9900;
    while(i--){
    gets(s)    ; // @@ [The function 'gets' is unsafe and has been removed from the C standard library in C11; using it may cause compilation errors or warnings. Additionally, the program logic does not implement DFS/BFS traversal as required by the problem description—it merely reads and prints input lines.]
    puts(s);//TODO
    }return 0;
}