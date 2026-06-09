#include<stdio.h>
int main()
{
    int a;
    while(scanf("%d",&a)!=EOF)
    {
        printf("%d ",a); // @@ This line prints every input number as it is read, instead of processing the graph and performing DFS/BFS traversals before and after vertex deletion. The program completely ignores the problem requirements and just echoes input.
    }
    return 0;
}