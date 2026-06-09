#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int main(){
    int n,m,d;
    scanf("%d %d",&n,&m);
    printf("%d %d\n",n,m); // @@ Error: This line prints the input values instead of the required DFS/BFS traversal sequences; it should be removed and replaced with traversal logic.
    int bian[m][2]; 
    int visited[n];
    for(int i=0;i<m;i++){
        scanf("%d %d",&bian[i][0],&bian[i][1]);
        printf("%d %d\n",bian[i][0],bian[i][1]); // @@ Error: This line prints each edge instead of the traversal sequences after deletion; it should be removed and replaced with traversal logic.
    }
    scanf("%d",&d);
    printf("%d",d); // @@ Error: This line prints the deleted vertex number, which is not part of the output format; expected output consists of four lines of traversal sequences.
    return 0;
}