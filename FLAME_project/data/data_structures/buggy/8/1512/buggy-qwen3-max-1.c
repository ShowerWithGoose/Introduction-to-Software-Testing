#include<stdio.h>
int main()
{
    int n1,n2;
    int l,r;
    int del;
    scanf("%d %d",&n1,&n2);
    printf("%d %d\n",n1,n2); // @@ [This line incorrectly outputs the input n1 and n2 instead of performing graph traversal. The entire program logic is missing and just echoes inputs.]
    for(int i=0;i<n2;i++)
    {
        scanf("%d %d",&l,&r);
        printf("%d %d\n",l,r); // @@ [This line incorrectly outputs each edge as it is read, rather than building a graph and performing DFS/BFS traversals.]
    }
    scanf("%d",&del);
    printf("%d",del); // @@ [This line only prints the deleted vertex, but the problem requires outputting four lines of traversal sequences (DFS/BFS before and after deletion).]
    return 0;
}