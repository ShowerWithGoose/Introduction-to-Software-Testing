#include<stdio.h>
int main(){
    char s[1005];
    int i=9900; // @@ [Error: arbitrary magic number; should read n and m from input, not set a fixed loop count]
    while(i--){ // @@ [Error: loop does not correspond to the number of edges or graph operations; should process exactly m edges and then delete vertex]
    gets(s)    ; // @@ [Error: unsafe gets() function; should use scanf to read edges and vertex number; also does not parse input correctly]
    puts(s);//TODO // @@ [Error: only echoes input; no graph construction or DFS/BFS traversal; should output traversal sequences]
    }return 0;
}