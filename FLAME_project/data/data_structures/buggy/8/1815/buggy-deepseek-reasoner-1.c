#include<stdio.h>
#include<ctype.h>
#include<string.h>
#include<stdlib.h>
int main()
{
    int a,b;
    while(scanf("%d %d",&a,&b)!=EOF) // @@ This line incorrectly treats all input as pairs; should first read n,m, then loop m times for edges, then read a single vertex.
    {
        printf("%d %d\n",a,b); // @@ This line prints all pairs instead of performing DFS/BFS traversals as required.
    }
    return 0;
}