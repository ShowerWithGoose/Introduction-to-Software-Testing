#include<stdio.h>
int main()
{
    int a;
    while(scanf("%d",&a)!=EOF) // @@ Error: Input format requires reading n first, then reading n integers. This loop reads until EOF, which does not match the BST construction and leaf output requirement. Also, it does not read n separately.
    {
        printf("%d ",a); // @@ Error: Output should be for leaf nodes only, each on separate line with value and height. This prints all input space‑separated, not the required leaf node values and heights.
    }
    return 0;
}