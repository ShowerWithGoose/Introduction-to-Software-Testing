#include<stdio.h>
int main()
{ // @@ The program does not implement DFS/BFS traversals as required.
    int n1,n2;
    int l,r;
    int del;
    scanf("%d %d",&n1,&n2);
    printf("%d %d\n",n1,n2); // @@ Incorrect output: should output DFS and BFS sequences, not the input data.
    for(int i=0;i<n2;i++)
    {
        scanf("%d %d",&l,&r);
        printf("%d %d\n",l,r); // @@ Incorrect output: printing edges instead of traversal sequences.
    }
    scanf("%d",&del);
    printf("%d",del); // @@ Incorrect output: only prints deleted vertex, not DFS/BFS after deletion.
    return 0;
}