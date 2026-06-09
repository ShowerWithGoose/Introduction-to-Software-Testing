#include <stdio.h>


int main() 
{
    int n;
    scanf("%d",&n);
    
    if(n==1)
    {
        printf("1");
    }
    if(n==2) // @@ [Using 'if' instead of 'else if' causes multiple blocks to execute when n >= 2, leading to incorrect combined output]
    {
        printf("1 2 \n2 1 "); // @@ [Extra space after '2' and before newline may cause formatting mismatch; expected no trailing space]
        
    }
    if(n==3) // @@ [Using 'if' instead of 'else if' causes this block to also run when n==2 or n==1 if conditions overlap, but more critically, for n=3 it runs along with others if not exclusive]
    {
        printf("1 2 3\n1 3 2 \n2 1 3 \n2 3 1\n3 1 2\n3 2 1"); // @@ [Inconsistent spacing: some lines have trailing spaces (e.g., "1 3 2 "), which violates output format]
    }
    if(n==4) // @@ [Should be 'else if' to ensure only one block executes; using 'if' leads to execution of this and possibly other blocks for same n]
    {
        printf("1 2 3 4\n1 2 4 3\n1 3 2 4\n1 3 4 2\n1 4 2 3\n1 4 3 2\n2 1 3 4\n2 1 4 3\n2 3 1 4\n2 3 4 1\n2 4 1 3 \n2 4 3 1\n3 1 2 4\n3 1 4 2\n3 2 1 4\n3 2 4 1\n3 4 1 2\n3 4 2 1\n4 1 2 3\n4 1 3 2\n4 2 1 3\n4 2 3 1\n4 3 1 2\n4 3 2 1\n"); // @@ [Trailing space in "2 4 1 3 " and extra newline at end may cause formatting errors]
    }
    if(n==5) // @@ [Should be 'else if'; also, output is just "1", which is completely wrong for n=5 — missing all permutations]
    {
        printf("1"); // @@ [This outputs only "1" instead of all 120 permutations of 1..5 in lex order — major logic error due to incomplete implementation]
    }
                    
    return 0;
}