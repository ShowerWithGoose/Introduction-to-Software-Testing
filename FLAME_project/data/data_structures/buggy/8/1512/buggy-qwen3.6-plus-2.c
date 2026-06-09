#include<stdio.h>
int main()
{
    int n1,n2;
    int l,r;
    int del;
    scanf("%d %d",&n1,&n2);
    printf("%d %d\n",n1,n2); // @@ The program merely echoes the input instead of performing graph traversal (DFS/BFS) as required by the problem description.
    for(int i=0;i<n2;i++)
    {
        scanf("%d %d",&l,&r);
        printf("%d %d\n",l,r); // @@ The program merely echoes the input edges instead of building a graph structure and performing traversals.
    }
    scanf("%d",&del);
    printf("%d",del); // @@ The program merely echoes the deleted vertex instead of outputting the DFS and BFS sequences before and after deletion.
    return 0;
}