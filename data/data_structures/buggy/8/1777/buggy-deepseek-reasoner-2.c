#include <math.h>
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int main()
{
    int n,m;
    while(~scanf("%d%d",&n,&m)) // @@ This line initiates an infinite loop reading pairs of integers, but the program should read the graph once and then process it. The loop prevents proper execution of the required graph operations (DFS, BFS, deletion). It also reads indefinitely until EOF, which is not the intended behavior.
    {
        printf("%d %d\n",n,m); // @@ This line incorrectly outputs the input numbers instead of performing graph traversals. The program must output vertex sequences for DFS and BFS before and after deletion, not the raw input.
    }
    return 0;
}