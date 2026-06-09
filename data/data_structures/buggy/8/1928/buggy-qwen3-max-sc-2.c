#include<stdio.h>

int main()
{
    int x;
    while(scanf("%d",&x)!=EOF)
    
    printf("%d\n",x); // @@ [Missing braces around loop body causes only the next statement to be considered part of the loop; however, in this case, there is no statement between the while condition and printf, leading to unintended behavior. Also, the program logic does not implement graph traversal (DFS/BFS), vertex deletion, or handle input as per problem requirements.]
    return 0;
}