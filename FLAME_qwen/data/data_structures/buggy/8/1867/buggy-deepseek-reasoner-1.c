#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int main(){ // @@ The main function does not perform any graph traversal; the program is incomplete and does not output DFS/BFS sequences as required.
    int n,m,d;
    scanf("%d %d",&n,&m);
    printf("%d %d\n",n,m); // @@ Printing the input values is not part of the required output; this line does not contribute to the solution.
    int bian[m][2]; // @@ Variable-length array 'bian' declared but never used to construct the adjacency matrix; no graph structure is built.
    int visited[n]; // @@ 'visited' array is declared but never used in any traversal; it serves no purpose.
    for(int i=0;i<m;i++){
        scanf("%d %d",&bian[i][0],&bian[i][1]);
        printf("%d %d\n",bian[i][0],bian[i][1]); // @@ Printing edges is unnecessary; the required output is traversal sequences, not the input edges.
    }
    scanf("%d",&d);
    printf("%d",d); // @@ Printing the deleted vertex is not required; missing newline and no further processing.
    return 0;
}