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
    else if(n==2)
    {
        printf("1 2\n"); // @@ The expected output for N=2 is "1 2 " (with a trailing space and no newline, or potentially just "1 2" depending on strictness, but the bug report shows Expected Output: "1 2 ". The reference program outputs "1 2 \n2 1 ". The current code outputs "1 2\n". The test case failure indicates a mismatch. Looking at the reference program, it prints "1 2 \n2 1 ". The expected output in the prompt is "1 2 ". This suggests the last line should not have a newline, or there is a trailing space requirement. However, usually, permutations problems require specific formatting. Let's look closer at the reference. Reference for n=2: `printf("1 2 \n2 1 ");`. This means line 1 is "1 2 " followed by newline. Line 2 is "2 1 ". The current code prints "1 2\n" then "2 1\n". The difference is the trailing space. The expected output shown is `1 2 `. It seems the judge expects a trailing space after each number sequence, or specifically matches the reference format which includes trailing spaces before newlines.
        printf("2 1\n"); // @@ Similar to above, the reference output is "2 1 " (with trailing space, no newline at end of file potentially, or just trailing space). The current code prints "2 1\n". If the expected output is strictly "1 2 ", then the first line is the issue. If the expected output implies the whole block, the formatting is inconsistent with the reference which uses trailing spaces.
    }
    else if(n==3)
    {
        printf("1 2 3\n"); // @@ Missing trailing space compared to reference style "1 2 3 \n"
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
    printf("4 1 2 3 5 \n"); // @@ Duplicate line. This should be "4 1 2 5 3 \n" based on lexicographical order. The previous line is "4 1 2 3 5". The next distinct permutation starting with 4 1 2 is 4 1 2 5 3. This line repeats 4 1 2 3 5.
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