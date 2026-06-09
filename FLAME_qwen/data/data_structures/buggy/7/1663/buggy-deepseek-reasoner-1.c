#include<stdio.h>
int main()
{
    int a;
    while(scanf("%d",&a)!=EOF) // @@ The problem requires reading a fixed number n first, then n integers, and building a BST, not reading until EOF.
    {
        printf("%d ",a); // @@ Should output leaf node values and heights in the required format, not all integers separated by spaces.
    }
    return 0; // @@ Entire program does not implement the specified functionality.
}