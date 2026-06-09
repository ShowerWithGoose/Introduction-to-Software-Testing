#include<stdio.h>
#include<ctype.h>
#include<string.h>
#include<stdlib.h>
int main() // @@ [The provided source code is completely different from the reference program and the problem description. It only reads and prints integers, failing to implement graph construction, DFS, BFS, or vertex deletion logic.]
{
    int a,b; // @@ [Variable names conflict with global variables in the reference logic if this were part of the same file, but primarily this main function lacks all required graph algorithms.]
    while(scanf("%d %d",&a,&b)!=EOF) // @@ [This loop simply echoes input pairs instead of building an adjacency matrix or processing graph edges.]
    {
        printf("%d %d\n",a,b); // @@ [This output is incorrect; it should perform traversals and print vertex sequences as per the problem statement.]
    }
    return 0;
}