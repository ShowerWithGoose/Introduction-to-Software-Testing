#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int main(){
    int n,m,d;
    scanf("%d %d",&n,&m);
    printf("%d %d\n",n,m); // @@ Unnecessary output that violates the specified output format.
    int bian[m][2];  // @@ Incorrect data structure; should use an adjacency matrix for graph traversal.
    int visited[n]; // @@ Array is uninitialized; must be set to 0 to correctly track visited vertices.
    for(int i=0;i<m;i++){
        scanf("%d %d",&bian[i][0],&bian[i][1]);
        printf("%d %d\n",bian[i][0],bian[i][1]); // @@ Unnecessary output that violates the specified output format.
    }
    scanf("%d",&d);
    printf("%d",d); // @@ Unnecessary output that violates the specified output format.
    return 0; // @@ Missing implementation of DFS, BFS, and vertex deletion logic.
}