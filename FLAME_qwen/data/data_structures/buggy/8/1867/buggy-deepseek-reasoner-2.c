#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int main(){
    int n,m,d;
    scanf("%d %d",&n,&m);
    printf("%d %d\n",n,m); // @@ This line prints the number of vertices and edges instead of the required traversal sequences. The program should output DFS and BFS sequences before and after deletion, not the input.
    int bian[m][2]; 
    int visited[n]; // @@ The visited array is declared but never used for graph traversal. It should be initialized and used to track visited vertices during DFS/BFS, but no traversal functions are implemented.
    for(int i=0;i<m;i++){
        scanf("%d %d",&bian[i][0],&bian[i][1]);
        printf("%d %d\n",bian[i][0],bian[i][1]); // @@ This line prints each edge, which is not part of the required output. The program should instead build the graph structure and perform traversals.
    }
    scanf("%d",&d);
    printf("%d",d); // @@ This line prints the deleted vertex, but the expected output must include the DFS and BFS sequences for both before and after deletion, not just the vertex number.
    return 0;
}