#include<stdio.h>
int main()
{
    int n1,n2;
    int l,r;
    int del;
    scanf("%d %d",&n1,&n2);
    printf("%d %d\n",n1,n2); // @@ [This line incorrectly outputs the input n1 and n2 instead of performing graph traversal. The entire program is just echoing inputs, not implementing DFS/BFS or graph operations as required.]
    for(int i=0;i<n2;i++)
    {
        scanf("%d %d",&l,&r);
        printf("%d %d\n",l,r); // @@ [This line incorrectly outputs each edge as it is read, rather than building a graph structure for traversal.]
    }
    scanf("%d",&del);
    printf("%d",del); // @@ [This line only outputs the deleted vertex, but the problem requires outputting DFS and BFS traversal sequences before and after deletion.]
    return 0;
}