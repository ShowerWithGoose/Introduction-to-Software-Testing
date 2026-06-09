#include<stdio.h>
int main(){
    char s[1005];
    int i=9900;
    while(i--){
    gets(s)    ; // @@ 'gets' is deprecated and removed in the C11 standard, causing compilation errors in modern environments. Additionally, the code completely lacks graph data structures, DFS/BFS traversal algorithms, and vertex deletion logic required by the problem.
    puts(s);//TODO // @@ This line merely echoes the raw input string instead of computing and outputting the required DFS and BFS traversal sequences before and after deleting the specified vertex.
    }return 0;
}