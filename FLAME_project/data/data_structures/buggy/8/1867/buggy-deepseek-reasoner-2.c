#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int main(){
    int n,m,d;
    scanf("%d %d",&n,&m);
    printf("%d %d\n",n,m); // @@ This line prints the input line as output, but the expected output consists of traversal sequences, not the input. This line should be removed or replaced with the actual DFS/BFS output.
    int bian[m][2]; 
    int visited[n];
    for(int i=0;i<m;i++){
        scanf("%d %d",&bian[i][0],&bian[i][1]);
        printf("%d %d\n",bian[i][0],bian[i][1]); // @@ This line prints each edge, which is not part of the required output. This should be removed; the program must perform graph traversals and print vertex sequences.
    }
    scanf("%d",&d);
    printf("%d",d); // @@ This line prints the deleted vertex as a lonely number, but the output should be traversal sequences. This line should not exist; instead, the program should compute DFS and BFS before and after deletion.
    return 0;
}