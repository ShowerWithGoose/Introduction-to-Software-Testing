#include<stdio.h>
int main()
{
    int a;
    while(scanf("%d",&a)!=EOF) // @@ The program incorrectly reads all input as a single stream of integers, ignoring the required format (n, m, edges, deleted vertex). It does not construct a graph or perform DFS/BFS traversals, thus producing no correct output for the problem.
    {
        printf("%d ",a); // @@ This prints every integer read, which is completely unrelated to the required output (DFS and BFS sequences before and after deletion).
    }
    return 0;
}