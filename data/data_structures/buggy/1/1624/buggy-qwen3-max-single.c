#include <stdio.h>


int main() 
{
    int n;
    scanf("%d",&n);
    
    if(n==1)
    {
        printf("1");
    }
    if(n==2) @@ [Using independent 'if' statements instead of 'else if' causes multiple blocks to execute when n >= 2, leading to incorrect combined output. Also, extra spaces before '\n' or at end of lines may cause formatting mismatch.]
    {
        printf("1 2 \n2 1 "); @@ [Trailing space after "2 1" and space before '\n' in "1 2 \n" violate exact output format; expected no trailing spaces.]
        
    }
    if(n==3) @@ [Should be 'else if' to prevent execution when n > 3; also inconsistent spacing in output strings.]
    {
        printf("1 2 3\n1 3 2 \n2 1 3 \n2 3 1\n3 1 2\n3 2 1"); @@ [Lines "1 3 2 " and "2 1 3 " have trailing spaces, which are not allowed per output format.]
    }
    if(n==4) @@ [Should be 'else if'; without it, if n==5, both n==4 and n==5 blocks might not run, but more critically, for n=2,3,4, multiple prints occur.]
    {
        printf("1 2 3 4\n1 2 4 3\n1 3 2 4\n1 3 4 2\n1 4 2 3\n1 4 3 2\n2 1 3 4\n2 1 4 3\n2 3 1 4\n2 3 4 1\n2 4 1 3 \n2 4 3 1\n3 1 2 4\n3 1 4 2\n3 2 1 4\n3 2 4 1\n3 4 1 2\n3 4 2 1\n4 1 2 3\n4 1 3 2\n4 2 1 3\n4 2 3 1\n4 3 1 2\n4 3 2 1\n"); @@ [Line "2 4 1 3 " has a trailing space; also an extra newline at the very end due to trailing '\n', which may cause presentation error.]
    }
    if(n==5) @@ [Should be 'else if'; currently, for n=5, only prints "1", which is completely wrong. Also, missing cases for n=6 to 10 as per problem constraint (1<=N<=10), but even for n=5 it's incorrect.]
    {
        printf("1"); @@ [This outputs only "1" for n=5, but should output all 120 permutations in lexicographical order.]
    }
                    
    return 0;
}