#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int main(){
    int n,m,d;
    scanf("%d %d",&n,&m);
    printf("%d %d\n",n,m); // @@ The program incorrectly prints the input values (n, m) instead of performing graph traversal and outputting DFS/BFS sequences.
    int bian[m][2]; 
    int visited[n];
    for(int i=0;i<m;i++){
        scanf("%d %d",&bian[i][0],&bian[i][1]);
        printf("%d %d\n",bian[i][0],bian[i][1]); // @@ The program incorrectly prints the edge inputs instead of building the graph and traversing it.
    }
    scanf("%d",&d);
    printf("%d",d); // @@ The program incorrectly prints the deleted vertex instead of performing the required traversals on the modified graph.
    return 0;
}