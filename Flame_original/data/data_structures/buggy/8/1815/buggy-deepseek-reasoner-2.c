#include<stdio.h>
#include<ctype.h>
#include<string.h>
#include<stdlib.h>
int main()
{
    int a,b;
    while(scanf("%d %d",&a,&b)!=EOF) // @@ [The loop reads pairs of integers but the input format consists of n, m, then m edges (each an edge pair), then a single delete vertex. This loop will either read too many or too few numbers and never terminate correctly. Also it does not stop after reading the delete vertex, so it cannot process the actual DFS/BFS traversal.]
    {
        printf("%d %d\n",a,b); // @@ [This prints the raw input pairs, not the required traversal sequences (DFS and BFS before and after deletion). The program must output vertex orderings, not just echo the input.]
    }
    return 0;
}