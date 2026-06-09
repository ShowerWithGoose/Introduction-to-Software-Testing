#include<stdio.h>
int main()
{
    int n1,n2;
    int l,r;
    int del;
    scanf("%d %d",&n1,&n2);
    printf("%d %d\n",n1,n2); // @@ The program incorrectly echoes the input instead of storing the graph and performing DFS/BFS traversals.
    for(int i=0;i<n2;i++)
    {
        scanf("%d %d",&l,&r);
        printf("%d %d\n",l,r); // @@ The program should store edges in an adjacency structure for traversal, not print them.
    }
    scanf("%d",&del);
    printf("%d",del); // @@ The program should output DFS and BFS sequences before and after deletion, not print the deleted vertex.
    return 0;
}