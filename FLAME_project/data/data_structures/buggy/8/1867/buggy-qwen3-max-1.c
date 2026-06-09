#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int main(){
    int n,m,d;
    scanf("%d %d",&n,&m);
    printf("%d %d\n",n,m); // @@ [The program incorrectly outputs the input values instead of performing DFS/BFS traversals. It should not print n and m.]
    int bian[m][2]; 
    int visited[n];
    for(int i=0;i<m;i++){
        scanf("%d %d",&bian[i][0],&bian[i][1]);
        printf("%d %d\n",bian[i][0],bian[i][1]); // @@ [The program incorrectly echoes each edge as it reads it, which is not part of the required output.]
    }
    scanf("%d",&d);
    printf("%d",d); // @@ [The program incorrectly prints the deleted vertex instead of performing and outputting the four traversal sequences (DFS before, BFS before, DFS after, BFS after).]
    return 0;
}