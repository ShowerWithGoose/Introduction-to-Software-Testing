#include<stdio.h>
#include<ctype.h>
#include<string.h>
#include<stdlib.h>
int main()
{
    int a,b;
    while(scanf("%d %d",&a,&b)!=EOF) // @@ Error: This loop reads pairs indefinitely, but the input format requires reading n and m first, then m edges, then a single delete vertex. The program should first read n and m, then loop m times reading edges, then read delete vertex.
    {
        printf("%d %d\n",a,b); // @@ Error: This prints the input pairs, but the program is supposed to perform DFS and BFS traversals and output sequences before and after deletion. This line should be replaced with traversal logic.
    }
    return 0;
}