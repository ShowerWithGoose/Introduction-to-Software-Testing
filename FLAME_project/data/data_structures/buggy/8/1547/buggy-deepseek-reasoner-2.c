#include<stdio.h>
#include<stdlib.h>
int main()
{
    char data[1005];
    char c;
    while(scanf("%c",&c)!=EOF) // @@ The program incorrectly reads and echoes the input instead of parsing the graph and performing DFS/BFS traversals as required.
    {
        printf("%c",c);
    }
    return 0;
    
}