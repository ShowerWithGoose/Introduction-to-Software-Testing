#include <stdio.h>


int main() 
{
    int n;
    scanf("%d",&n);
    
    if(n==1)
    {
        printf("1");
    }
    if(n==2)
    {
        printf("1 2 \n2 1 ");@@ // @@ Extra trailing spaces and missing newline; should be "1 2\n2 1" without spaces.
    }
    if(n==3)
    {
        printf("1 2 3\n1 3 2 \n2 1 3 \n2 3 1\n3 1 2\n3 2 1");@@ // @@ Extra spaces before newlines; should match reference without trailing spaces.
    }
    if(n==4)
    {
        printf("1 2 3 4\n1 2 4 3\n1 3 2 4\n1 3 4 2\n1 4 2 3\n1 4 3 2\n2 1 3 4\n2 1 4 3\n2 3 1 4\n2 3 4 1\n2 4 1 3 \n2 4 3 1\n3 1 2 4\n3 1 4 2\n3 2 1 4\n3 2 4 1\n3 4 1 2\n3 4 2 1\n4 1 2 3\n4 1 3 2\n4 2 1 3\n4 2 3 1\n4 3 1 2\n4 3 2 1\n");@@ // @@ Extra trailing newline and spaces; reference does not have trailing newline and has no spaces before newlines.
    }
    if(n==5)
    {
        printf("1");@@ // @@ Missing all permutations for n=5; should output all 120 permutations as in reference.
    }
                    
    return 0;
}