#include<stdio.h>
int main()
{
    int n1,n2;
    int l,r;
    int del;
    scanf("%d %d",&n1,&n2);
    printf("%d %d\n",n1,n2); // @@ Incorrectly prints the input values (number of vertices and edges) instead of traversal sequences. This line should not exist.
    for(int i=0;i<n2;i++)
    {
        scanf("%d %d",&l,&r);
        printf("%d %d\n",l,r); // @@ Incorrectly prints each edge input instead of traversal sequences. This line should not exist.
    }
    scanf("%d",&del);
    printf("%d",del); // @@ Incorrectly prints the deletion vertex instead of traversal sequences. Also missing newline. This line should not exist.
    return 0;
}