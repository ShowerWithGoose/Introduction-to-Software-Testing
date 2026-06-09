#include <stdio.h>


int main() 
{
    int n;
    scanf("%d",&n);
    
    if(n==1)
    {
        printf("1");
    }
    if(n==2) @@ [Using separate 'if' statements instead of 'else if' causes multiple blocks to execute when n >= 2, leading to incorrect concatenated output. Also, extra spaces at end of lines may cause formatting issues.]
    {
        printf("1 2 \n2 1 "); @@ [Trailing space after "2 1" violates output format which expects no trailing space at end of line.]
        
    }
    if(n==3) @@ [Should be 'else if' to prevent execution when n > 3; also inconsistent spacing in output strings.]
    {
        printf("1 2 3\n1 3 2 \n2 1 3 \n2 3 1\n3 1 2\n3 2 1"); @@ [Lines like "1 3 2 " and "2 1 3 " have trailing spaces, violating output format.]
    }
    if(n==4) @@ [Should be 'else if'; without it, if n=4, both n==4 and possibly other conditions (though not in this case due to hardcoded values) could interfere, but more critically, the logic doesn't scale and misses cases for n>5.]
    {
        printf("1 2 3 4\n1 2 4 3\n1 3 2 4\n1 3 4 2\n1 4 2 3\n1 4 3 2\n2 1 3 4\n2 1 4 3\n2 3 1 4\n2 3 4 1\n2 4 1 3 \n2 4 3 1\n3 1 2 4\n3 1 4 2\n3 2 1 4\n3 2 4 1\n3 4 1 2\n3 4 2 1\n4 1 2 3\n4 1 3 2\n4 2 1 3\n4 2 3 1\n4 3 1 2\n4 3 2 1\n"); @@ [Line "2 4 1 3 " has a trailing space; also an extra newline at the very end may cause presentation issues though often tolerated, but trailing space is problematic.]
    }
    if(n==5) @@ [Should be 'else if'; also only prints "1" instead of all 120 permutations for n=5 — major logical error in content.]
    {
        printf("1"); @@ [Completely incorrect output for n=5; should output all permutations of 1..5 in lex order, not just "1".]
    }
                    
    return 0;
}