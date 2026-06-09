#include<stdio.h>
#include<ctype.h>
#include<string.h>
#include<stdlib.h>
int main()
{
    int a,b;
    while(scanf("%d %d",&a,&b)!=EOF) // @@ [This loop reads all input as integer pairs, ignoring the actual graph structure and delete vertex. It does not perform DFS or BFS traversals as required.]
    {
        printf("%d %d\n",a,b); // @@ [This prints the raw input pairs instead of the required vertex sequences for DFS and BFS before and after deletion.]
    }
    return 0;
}