#include <stdio.h>
#include <math.h>
#include <string.h>
int main()
{
    int n;
    scanf("%d",&n);
    if(n==1)
    {
        printf("1\n");
    }
    else if(n==2) // @@ The expected output for N=2 is "1 2 " (with a trailing space and no newline, or potentially just "1 2" depending on strictness, but the reference shows "1 2 \n2 1 "). However, looking at the Buggy Output "1 2\n2 1\n" vs Expected "1 2 ", it seems the test case expects only the first permutation or has a specific format issue. Actually, looking closely at the provided "Expected Output": `1 2 `. It contains a trailing space. The buggy output is `1 2\n2 1\n`. The problem asks for ALL permutations. The expected output in the prompt description for Test Case Input 2 is `1 2 `. This is extremely suspicious as it misses the second permutation `2 1`. However, usually, these problems require all permutations. Let's look at the Reference Program. For n=2, it prints `1 2 \n2 1 `. Note the trailing spaces. The Buggy Code prints `1 2\n` and `2 1\n`. The difference is the trailing space. Many online judges are strict about whitespace. The error is likely the missing trailing space in the printf statements for all cases, not just n=2. But specifically for the failed test case n=2:
    {
        printf("1 2\n"); // @@ Missing trailing space. Expected format likely requires a space after the last number, e.g., "1 2 ". Or the judge compares strictly against reference which has "1 2 \n".
        printf("2 1\n"); // @@ Missing trailing space. Expected format likely requires a space after the last number, e.g., "2 1 ".
    }
    else if(n==3)
    {
        printf("1 2 3\n"); // @@ Missing trailing space compared to reference program style "1 2 3 \n"
        printf("1 3 2 \n");
        printf("2 1 3 \n");
        printf("2 3 1 \n");
        printf("3 1 2 \n");
        printf("3 2 1 \n");
    }
    else if(n==4)
    {
        printf("1 2 3 4 \n");
        printf("1 2 4 3 \n");
        printf("1 3 2 4 \n");
        printf("1 3 4 2 \n");
        printf("1 4 2 3 \n");
        printf("1 4 3 2 \n");
        printf("2 1 3 4 \n");
        printf("2 1 4 3 \n");
        printf("2 3 1 4 \n");
        printf("2 3 4 1 \n");
        printf("2 4 1 3 \n");
        printf("2 4 3 1 \n");
        printf("3 1 2 4 \n");
        printf("3 1 4 2 \n");
        printf("3 2 1 4 \n");
        printf("3 2 4 1 \n");
        printf("3 4 1 2 \n");
        printf("3 4 2 1 \n");
        printf("4 1 2 3 \n");
        printf("4 1 3 2 \n");
        printf("4 2 1 3 \n");
        printf("4 2 3 1 \n");
        printf("4 3 1 2 \n");
        printf("4 3 2 1 \n");
    }
    else if(n==5)
    {
    printf("1 2 3 4 5 \n");        
    printf("1 2 3 5 4 \n");    
    printf("1 2 4 3 5 \n");        
    printf("1 2 4 5 3 \n");        
    printf("1 2 5 3 4 \n");        
    printf("1 2 5 4 3 \n");        
    printf("1 3 2 4 5 \n");        
    printf("1 3 2 5 4 \n");    
    printf("1 3 4 2 5 \n");    
    printf("1 3 4 5 2 \n");        
    printf("1 3 5 2 4 \n");        
    printf("1 3 5 4 2 \n");        
    printf("1 4 2 3 5 \n");        
    printf("1 4 2 5 3 \n");        
    printf("1 4 3 2 5 \n");        
    printf("1 4 3 5 2 \n");        
    printf("1 4 5 2 3 \n");        
    printf("1 4 5 3 2 \n");        
    printf("1 5 2 3 4 \n");        
    printf("1 5 2 4 3 \n");        
    printf("1 5 3 2 4 \n");        
    printf("1 5 3 4 2 \n");        
    printf("1 5 4 2 3 \n");        
    printf("1 5 4 3 2 \n");        
    printf("2 1 3 4 5 \n");        
    printf("2 1 3 5 4 \n");        
    printf("2 1 4 3 5 \n");        
    printf("2 1 4 5 3 \n");        
    printf("2 1 5 3 4 \n");        
    printf("2 1 5 4 3 \n");        
    printf("2 3 1 4 5 \n");        
    printf("2 3 1 5 4 \n");        
    printf("2 3 4 1 5 \n");        
    printf("2 3 4 5 1 \n");        
    printf("2 3 5 1 4 \n");    
    printf("2 3 5 4 1 \n");    
    printf("2 4 1 3 5 \n");        
    printf("2 4 1 5 3 \n");        
    printf("2 4 3 1 5 \n");        
    printf("2 4 3 5 1 \n");        
    printf("2 4 5 1 3 \n");        
    printf("2 4 5 3 1 \n");        
    printf("2 5 1 3 4 \n");    
    printf("2 5 1 4 3 \n");        
    printf("2 5 3 1 4 \n");        
    printf("2 5 3 4 1 \n");        
    printf("2 5 4 1 3 \n");        
    printf("2 5 4 3 1 \n");        
    printf("3 1 2 4 5 \n");        
    printf("3 1 2 5 4 \n");        
    printf("3 1 4 2 5 \n");        
    printf("3 1 4 5 2 \n");        
    printf("3 1 5 2 4 \n");        
    printf("3 1 5 4 2 \n");        
    printf("3 2 1 4 5 \n");        
    printf("3 2 1 5 4 \n");        
    printf("3 2 4 1 5 \n");        
    printf("3 2 4 5 1 \n");        
    printf("3 2 5 1 4 \n");        
    printf("3 2 5 4 1 \n");        
    printf("3 4 1 2 5 \n");        
    printf("3 4 1 5 2 \n");        
    printf("3 4 2 1 5 \n");        
    printf("3 4 2 5 1 \n");    
    printf("3 4 5 1 2 \n");        
    printf("3 4 5 2 1 \n");        
    printf("3 5 1 2 4 \n");        
    printf("3 5 1 4 2 \n");        
    printf("3 5 2 1 4 \n");        
    printf("3 5 2 4 1 \n");        
    printf("3 5 4 1 2 \n");        
    printf("3 5 4 2 1 \n");        
    printf("4 1 2 3 5 \n");        
    printf("4 1 2 3 5 \n");        
    printf("4 1 2 5 3 \n");        
    printf("4 1 3 2 5 \n");        
    printf("4 1 3 5 2 \n");        
    printf("4 1 5 2 3 \n");        
    printf("4 1 5 3 2 \n");    
    printf("4 2 1 3 5 \n");        
    printf("4 2 1 5 3 \n");        
    printf("4 2 3 1 5 \n");    
    printf("4 2 3 5 1 \n");        
    printf("4 2 5 1 3 \n");        
    printf("4 2 5 3 1 \n");        
    printf("4 3 1 2 5 \n");        
    printf("4 3 1 5 2 \n");        
    printf("4 3 2 1 5 \n");        
    printf("4 3 2 5 1 \n");        
    printf("4 3 5 1 2 \n");        
    printf("4 3 5 2 1 \n");        
    printf("4 5 1 2 3 \n");        
    printf("4 5 1 3 2 \n");        
    printf("4 5 2 1 3 \n");        
    printf("4 5 2 3 1 \n");        
    printf("4 5 3 1 2 \n");        
    printf("4 5 3 2 1 \n");        
    printf("5 1 2 3 4 \n");        
    printf("5 1 2 4 3 \n");        
    printf("5 1 3 2 4 \n");        
    printf("5 1 3 4 2 \n");        
    printf("5 1 4 2 3 \n");        
    printf("5 1 4 3 2 \n");        
    printf("5 2 1 3 4 \n");        
    printf("5 2 1 4 3 \n");        
    printf("5 2 3 1 4 \n");        
    printf("5 2 3 4 1 \n");        
    printf("5 2 4 1 3 \n");        
    printf("5 2 4 3 1 \n");        
    printf("5 3 1 2 4 \n");    
    printf("5 3 1 4 2 \n");        
    printf("5 3 2 1 4 \n");        
    printf("5 3 2 4 1 \n");        
    printf("5 3 4 1 2 \n");        
    printf("5 3 4 2 1 \n");        
    printf("5 4 1 2 3 \n");        
    printf("5 4 1 3 2 \n");        
    printf("5 4 2 1 3 \n");    
    printf("5 4 2 3 1 \n");    
    printf("5 4 3 1 2 \n");        
    printf("5 4 3 2 1 \n");
    }
    return 0;
}