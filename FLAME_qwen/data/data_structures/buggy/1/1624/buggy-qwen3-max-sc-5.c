#include <stdio.h>


int main() 
{
    int n;
    scanf("%d",&n);
    
    if(n==1)
    {
        printf("1");
    }
    if(n==2) // @@ [Using separate 'if' statements instead of 'else if' causes multiple blocks to execute when n >= 2, leading to incorrect combined output. Also, extra spaces before newlines may cause formatting mismatches.]
    {
        printf("1 2 \n2 1 "); // @@ [Trailing space after "2" and before newline may cause output format mismatch; expected no trailing space at end of line.]
        
    }
    if(n==3) // @@ [Same issue: should be 'else if' to prevent multiple outputs for n>2. Also inconsistent spacing in output strings.]
    {
        printf("1 2 3\n1 3 2 \n2 1 3 \n2 3 1\n3 1 2\n3 2 1"); // @@ [Lines like "1 3 2 " and "2 1 3 " have trailing spaces, violating output format.]
    }
    if(n==4) // @@ [Should be 'else if'; also last line ends with '\n' which may add an extra blank line if not handled per spec.]
    {
        printf("1 2 3 4\n1 2 4 3\n1 3 2 4\n1 3 4 2\n1 4 2 3\n1 4 3 2\n2 1 3 4\n2 1 4 3\n2 3 1 4\n2 3 4 1\n2 4 1 3 \n2 4 3 1\n3 1 2 4\n3 1 4 2\n3 2 1 4\n3 2 4 1\n3 4 1 2\n3 4 2 1\n4 1 2 3\n4 1 3 2\n4 2 1 3\n4 2 3 1\n4 3 1 2\n4 3 2 1\n"); // @@ [Line "2 4 1 3 " has trailing space; final '\n' may cause extra newline beyond required N! lines.]
    }
    if(n==5) // @@ [Should be 'else if'; output is just "1", which is completely wrong for n=5 (should output 120 permutations).]
    {
        printf("1"); // @@ [This outputs only "1" instead of all 120 permutations for n=5, major logic error.]
    }
                    
    return 0;
}