#include<stdio.h>

int main()
{
    int x;
    while(scanf("%d",&x)!=EOF)
    
    printf("%d\n",x); // @@ [Missing braces around the loop body causes only the next statement to be considered inside the loop, but more critically, this program does not implement graph traversal logic at all—it merely echoes input integers, which is completely unrelated to the problem requirements. Additionally, the reference program uses gets() which is unsafe and deprecated, but the actual bug here is logical: the code doesn't solve the stated problem of performing DFS/BFS before and after vertex deletion.]
    return 0;
}