#include<stdio.h>
int main()
{
    int a; // @@ The program reads integers one by one but does not store them in an array or process them to perform graph traversal. It simply prints each integer, which results in outputting all input tokens including the number of vertices, edges, and edge pairs, instead of computing DFS and BFS sequences.
    while(scanf("%d",&a)!=EOF)
    {
        printf("%d ",a); // @@ This prints every integer read from input, including the graph size, edges, and the vertex to delete, producing a concatenated sequence of all input numbers. The expected output requires specific traversal sequences, not the raw input.
    }
    return 0;
}