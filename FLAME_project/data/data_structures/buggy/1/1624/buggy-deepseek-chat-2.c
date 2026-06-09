#include <stdio.h>


int main() 
{
    int n;
    scanf("%d",&n);
    
    if(n==1)
    {
        printf("1");
    }
    if(n==2) // @@ This should be else if to avoid executing both n==1 and n==2 cases when n==1; also output format missing newline and space consistency
    {
        printf("1 2 \n2 1 "); // @@ Missing newline after "1 2" and trailing space; expected output is "1 2 " with a newline, but here it prints "1 2 \n2 1 " which has extra space and no newline after first line
    }
    if(n==3)
    {
        printf("1 2 3\n1 3 2 \n2 1 3 \n2 3 1\n3 1 2\n3 2 1"); // @@ Inconsistent spacing: some lines have trailing spaces, e.g., "1 3 2 " and "2 1 3 "
    }
    if(n==4)
    {
        printf("1 2 3 4\n1 2 4 3\n1 3 2 4\n1 3 4 2\n1 4 2 3\n1 4 3 2\n2 1 3 4\n2 1 4 3\n2 3 1 4\n2 3 4 1\n2 4 1 3 \n2 4 3 1\n3 1 2 4\n3 1 4 2\n3 2 1 4\n3 2 4 1\n3 4 1 2\n3 4 2 1\n4 1 2 3\n4 1 3 2\n4 2 1 3\n4 2 3 1\n4 3 1 2\n4 3 2 1\n"); // @@ Inconsistent spacing: line "2 4 1 3 " has trailing space
    }
    if(n==5)
    {
        printf("1"); // @@ Incomplete: should print all permutations for n=5, not just "1"
    }
                    
    return 0;
}