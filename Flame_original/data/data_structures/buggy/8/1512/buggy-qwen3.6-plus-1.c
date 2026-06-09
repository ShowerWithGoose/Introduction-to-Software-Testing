#include<stdio.h>
int main()
{
    int n1,n2;
    int l,r;
    int del;
    scanf("%d %d",&n1,&n2);
    printf("%d %d\n",n1,n2); // @@ The program incorrectly echoes the input instead of building a graph and performing DFS/BFS traversals.
    for(int i=0;i<n2;i++)
    {
        scanf("%d %d",&l,&r);
        printf("%d %d\n",l,r); // @@ The program should store edges in an adjacency matrix or list rather than printing them immediately.
    }
    scanf("%d",&del);
    printf("%d",del); // @@ The program fails to implement vertex deletion and the required DFS/BFS traversals before and after deletion.
    return 0;
}