#include<stdio.h>
int main(){
    char s[1005];
    int i=9900; // @@ [Hardcoded loop count; should read input for number of vertices/edges]
    while(i--){ // @@ [Loop runs arbitrary number of times; logic should implement DFS and BFS traversals]
    gets(s)    ; // @@ [Unsafe gets() and does not parse integers; should read integers for graph construction]
    puts(s);//TODO // @@ [Prints raw input instead of traversal sequences; does not output required DFS/BFS results]
    }return 0;
}