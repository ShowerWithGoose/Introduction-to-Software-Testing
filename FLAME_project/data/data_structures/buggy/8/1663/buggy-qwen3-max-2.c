#include<stdio.h>
int main()
{
    int a;
    while(scanf("%d",&a)!=EOF)
    {
        printf("%d ",a); // @@ This line prints every input number as it is read, which results in echoing the entire input instead of performing graph traversal. The program completely ignores the problem requirements of building a graph, performing DFS/BFS before and after vertex deletion, and outputting traversal sequences.
    }
    return 0;
}