#include<stdio.h>

int main()
{
    int x;
    while(scanf("%d",&x)!=EOF)
    
    printf("%d\n",x);
    return 0;
} // @@ [The program logic is completely unrelated to the problem description. It merely reads integers and prints them, without implementing graph construction, DFS/BFS traversals, or vertex deletion. Additionally, the loop body for the while statement is missing braces, so only the next line would be considered inside the loop—but in this case, there's a blank line, making the loop infinite if input is provided, and no graph processing occurs at all. This leads to incorrect output for any valid test case of the described problem.]