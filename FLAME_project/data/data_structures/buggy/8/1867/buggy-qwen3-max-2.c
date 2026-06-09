#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int main(){
    int n,m,d;
    scanf("%d %d",&n,&m);
    printf("%d %d\n",n,m); // @@ [The program incorrectly outputs the input values instead of performing graph traversal. The problem requires DFS/BFS sequences, not echoing inputs.]
    int bian[m][2]; 
    int visited[n];
    for(int i=0;i<m;i++){
        scanf("%d %d",&bian[i][0],&bian[i][1]);
        printf("%d %d\n",bian[i][0],bian[i][1]); // @@ [Echoing input edges is wrong; the program should build a graph and perform traversals.]
    }
    scanf("%d",&d);
    printf("%d",d); // @@ [Echoing the deleted vertex is incorrect; the program must output traversal results before and after deletion.]
    return 0;
}