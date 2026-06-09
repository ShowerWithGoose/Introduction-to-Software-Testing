#include<stdio.h>
int main(){
    char s[1005];
    int i=9900;
    while(i--){
    gets(s)    ; // @@ [Using gets() is unsafe and deprecated; more critically, the entire program logic is wrong—it just echoes input lines instead of implementing DFS/BFS graph traversal as required.]
    puts(s);//TODO // @@ [This line merely prints back the input without performing any graph operations, leading to completely incorrect output for the problem.]
    }return 0;
}