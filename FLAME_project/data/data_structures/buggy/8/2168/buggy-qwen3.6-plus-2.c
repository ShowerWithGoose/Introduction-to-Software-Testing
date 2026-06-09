#include<stdio.h>

int main(){
    char c;
    while((c=getchar())!=EOF){
        printf("%c",c); // @@ The program simply echoes the input instead of implementing the graph traversal logic (DFS/BFS) and vertex deletion as required by the problem description. It fails to parse the graph structure, perform traversals, or handle the deletion of the specified vertex.
    }
}