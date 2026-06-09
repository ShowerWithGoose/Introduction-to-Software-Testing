#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int main(){
    int n,m,d;
    scanf("%d %d",&n,&m);
    printf("%d %d\n",n,m); // @@ This line prints the input values instead of performing graph traversal; the program should not output the input values.
    int bian[m][2]; 
    int visited[n];
    for(int i=0;i<m;i++){
        scanf("%d %d",&bian[i][0],&bian[i][1]);
        printf("%d %d\n",bian[i][0],bian[i][1]); // @@ This line prints the edges instead of performing graph traversal; the program should not output the edges.
    }
    scanf("%d",&d);
    printf("%d",d); // @@ This line prints the deleted vertex instead of performing graph traversal; the program should not output the deleted vertex.
    return 0;
}