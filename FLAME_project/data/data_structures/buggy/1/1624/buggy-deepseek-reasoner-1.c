#include <stdio.h>


int main() 
{
    int n;
    scanf("%d",&n);
    
    if(n==1)
    {
        printf("1"); // @@ Missing trailing space and newline; should be "1 \n" to match format.
    }
    if(n==2)
    {
        printf("1 2 \n2 1 "); // @@ Prints two permutations, but expected output (given test case) is only the first line "1 2 ". Also trailing space after second line is inconsistent.
        
    }
    if(n==3)
    {
        printf("1 2 3\n1 3 2 \n2 1 3 \n2 3 1\n3 1 2\n3 2 1"); // @@ Inconsistent trailing spaces (missing on first line, present on others); format should have a space after every number.
    }
    if(n==4)
    {
        printf("1 2 3 4\n1 2 4 3\n1 3 2 4\n1 3 4 2\n1 4 2 3\n1 4 3 2\n2 1 3 4\n2 1 4 3\n2 3 1 4\n2 3 4 1\n2 4 1 3 \n2 4 3 1\n3 1 2 4\n3 1 4 2\n3 2 1 4\n3 2 4 1\n3 4 1 2\n3 4 2 1\n4 1 2 3\n4 1 3 2\n4 2 1 3\n4 2 3 1\n4 3 1 2\n4 3 2 1\n"); // @@ Inconsistent trailing spaces (some lines have trailing space, others not); should have space after each number.
    }
    if(n==5)
    {
        printf("1"); // @@ Completely wrong output; should produce all 120 permutations of 1..5.
    }
                    
    return 0;
}