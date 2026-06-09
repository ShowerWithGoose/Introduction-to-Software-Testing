#include<stdio.h>
int main()
{
    int n1,n2;
    int l,r;
    int del;
    scanf("%d %d",&n1,&n2);
    printf("%d %d\n",n1,n2); // @@ This line incorrectly prints the number of vertices and edges; the output should only contain traversal sequences, not the input.
    for(int i=0;i<n2;i++)
    {
        scanf("%d %d",&l,&r);
        printf("%d %d\n",l,r); // @@ This line incorrectly prints each edge; the output should not include the edges.
    }
    scanf("%d",&del);
    printf("%d",del); // @@ This line incorrectly prints the deleted vertex; the program should output DFS and BFS sequences before and after deletion, not the vertex number.
    return 0;
}