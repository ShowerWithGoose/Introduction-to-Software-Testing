#include <stdio.h>


int main() 
{
    int n;
    scanf("%d",&n);
    
    if(n==1)
    {
        printf("1");
    }
    if(n==2) // @@ [Using separate 'if' statements instead of 'else if' causes multiple blocks to execute when n >= 2, leading to incorrect combined output. Also, extra spaces at end of lines may cause formatting mismatch.]
    {
        printf("1 2 \n2 1 "); // @@ [Trailing space after "2 1" and missing newline at end may cause output format mismatch with expected result.]
        
    }
    if(n==3) // @@ [Should be 'else if' to prevent execution when n > 3; also inconsistent spacing (e.g., "1 3 2 \n") introduces trailing spaces.]
    {
        printf("1 2 3\n1 3 2 \n2 1 3 \n2 3 1\n3 1 2\n3 2 1"); // @@ [Trailing spaces after "1 3 2" and "2 1 3" violate required output format (no trailing spaces).]
    }
    if(n==4) // @@ [Should be 'else if'; also has a trailing space in "2 4 1 3 \n" and an extra newline at the very end.]
    {
        printf("1 2 3 4\n1 2 4 3\n1 3 2 4\n1 3 4 2\n1 4 2 3\n1 4 3 2\n2 1 3 4\n2 1 4 3\n2 3 1 4\n2 3 4 1\n2 4 1 3 \n2 4 3 1\n3 1 2 4\n3 1 4 2\n3 2 1 4\n3 2 4 1\n3 4 1 2\n3 4 2 1\n4 1 2 3\n4 1 3 2\n4 2 1 3\n4 2 3 1\n4 3 1 2\n4 3 2 1\n"); // @@ [Trailing space in "2 4 1 3 " and extra newline at end of entire string cause formatting errors.]
    }
    if(n==5) // @@ [Should be 'else if'; only prints "1" instead of full permutation list for n=5, which is completely incorrect.]
    {
        printf("1"); // @@ [This outputs only "1" for n=5, but should output all 120 permutations in lexicographical order.]
    }
                    
    return 0;
}