#include<stdio.h>

int main(){
    char c;
    while((c=getchar())!=EOF){
        printf("%c",c);
    }
} // @@ [The entire program is incorrect: it simply echoes input characters instead of implementing graph traversal (DFS/BFS) before and after vertex deletion as required by the problem. It does not read or process graph data, perform traversals, or output vertex sequences.]