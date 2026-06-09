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
        printf("1 2 \n2 1 ");
        
    }
    if(n==3)
    {
        printf("1 2 3\n1 3 2 \n2 1 3 \n2 3 1\n3 1 2\n3 2 1");
    }
    if(n==4)
    {
        printf("1 2 3 4\n1 2 4 3\n1 3 2 4\n1 3 4 2\n1 4 2 3\n1 4 3 2\n2 1 3 4\n2 1 4 3\n2 3 1 4\n2 3 4 1\n2 4 1 3 \n2 4 3 1\n3 1 2 4\n3 1 4 2\n3 2 1 4\n3 2 4 1\n3 4 1 2\n3 4 2 1\n4 1 2 3\n4 1 3 2\n4 2 1 3\n4 2 3 1\n4 3 1 2\n4 3 2 1\n");
    }
    if(n==5) // @@ Incorrect logic: prints "1" instead of permutations, and the code lacks handling for N=6 to 10. Hardcoding is insufficient; a general recursive algorithm is needed.
    {
        printf("1"); // @@ Wrong output for N=5; should generate all 120 permutations in lexicographical order.
    }
                    
    return 0;
}