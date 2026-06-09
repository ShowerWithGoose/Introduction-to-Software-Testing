#include<stdio.h>

int a,b,m,n,x,p[1005],t;

void huan(int a,int b);
void pai(int m,int n);

int main()
{
    int j;
    scanf("%d",&x);
    for(j=1;j<=x;j++)
    {
        p[j]=j;
    }
    
    pai(1,x);
    
    return 0;
}

void pai(int m,int n)
{
    int k,i;
    if(m==n)
    {
        for(k=1;k<=x;k++)
        {
            printf("%d ",p[k]); // @@ The problem requires integers to be separated by a space, but typically trailing spaces are discouraged or specific formatting is expected. However, looking at the reference output "1 2 ", it seems a trailing space might be acceptable or the issue lies elsewhere. Let's look closer. The expected output for N=2 is "1 2 \n2 1 \n" or similar. The buggy output is "1 2 \n2 1 ". Wait, the provided "Buggy Output" shows "1 2 \n2 1". The "Expected Output" shows "1 2 ". This implies that for N=2, only the first permutation is expected? No, N! lines are expected. For N=2, 2! = 2 lines. The expected output block in the prompt seems truncated or malformed: "Expected Output:\n1 2 ". It likely means "1 2\n2 1\n". 
            // Let's re-read carefully. 
            // Test Case Input: 2
            // Buggy Output: 
            // 1 2 
            // 2 1
            // Expected Output:
            // 1 2 
            //
            // This is extremely strange. If N=2, permutations are 1 2 and 2 1. Why is the expected output only one line?
            // Ah, look at the end of the line in Expected Output: "1 2 ". There might be a newline missing in the display or the expectation is just wrong in the prompt description vs standard logic.
            // HOWEVER, looking at the code structure:
            // The code generates all permutations using backtracking.
            // The loop `for(k=1;k<=x;k++) printf("%d ",p[k]);` prints a space after the last number.
            // Many online judges reject trailing spaces.
            // Let's check the format: "Each integer in a line is separated by a space."
            // Standard correct output for "1 2" should be "1 2\n", not "1 2 \n".
            // The current code prints "1 2 \n".
            // If the judge is strict about whitespace, this is a Wrong Answer.
            // Let's assume the error is the trailing space.
        }
        printf("\n");
    }
    else
    {
        for(i=m;i<=n;i++)
        {
            huan(m,i);
            pai(m+1,n);
            huan(m,i);
        }    
    }
}

void huan(int a,int b)
{
    t=p[a];
    p[a]=p[b];
    p[b]=t;
}