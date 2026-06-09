#include<stdio.h>
#include<stdlib.h>
int main()
{
    char data[1005];
    char c;
    while(scanf("%c",&c)!=EOF) // @@ Program does not process input to perform graph traversals; it simply echoes input, causing wrong output.
    {
        printf("%c",c); // @@ Outputs raw input instead of the required DFS/BFS vertex sequences before and after deletion.
    }
    return 0;
    
}