#include<stdio.h>
#include<stdlib.h>
int main()
{
    char data[1005]; // @@ unused variable, no graph data structures declared
    char c;
    while(scanf("%c",&c)!=EOF) // @@ does not parse graph input (n,m,edges,delete vertex); just echoes characters
    {
        printf("%c",c); // @@ does not perform DFS/BFS or output sequences as required
    }
    return 0;
    
}