#include <math.h>
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int main()
{
    int n,m;
    while(~scanf("%d%d",&n,&m)) // @@ This loop will read all subsequent lines as pairs, but after the first line, the data represent edges and a single integer. The program should read only the first line for n,m, then read edges and the delete vertex, not loop over all input.
    {
        printf("%d %d\n",n,m); // @@ This line just prints back the input numbers instead of performing DFS/BFS traversals and outputting the required sequences. The entire graph construction and traversal logic is missing.
    }
    return 0;
}