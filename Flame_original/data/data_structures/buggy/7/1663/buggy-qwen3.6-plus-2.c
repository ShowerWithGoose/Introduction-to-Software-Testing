#include<stdio.h>
int main()
{
    int a; // @@ Missing BST node structure and necessary variables for tree construction.
    while(scanf("%d",&a)!=EOF) // @@ Incorrect input handling; should read n first, then n integers.
    {
        printf("%d ",a); // @@ Fails to implement BST insertion and leaf node height printing logic.
    }
    return 0;
}