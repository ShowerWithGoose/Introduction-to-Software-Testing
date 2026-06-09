#include<stdio.h>
int N,i,j,b[20];
char a[20];
void re(int m,int n);
int main()
{
scanf("%d",&N);
re(0,N);
return 0;
}
void re(int m,int n)
{
    if(n==0)
    {
        a[2*m]='\0'; // @@ The null terminator index is incorrect. Since m represents the current depth/position in the recursion and increases by 2 for each number added, the string length should be 2*N - 1 (for N numbers and N-1 spaces). When n==0, m equals 2*N. Setting a[2*m] to '\0' places it far beyond the actual content, but more importantly, the logic for constructing the string relies on `a` being properly terminated at the end of the full permutation. However, the critical error is that `puts(a)` prints the string. If N > 9, `(i+1)/2 + '0'` will not produce correct characters for digits 10+, but the constraint is N<=10. The main issue causing Wrong Answer for N=3 is likely related to how the output is formatted or terminated. Let's look closer. For N=3, m goes 0->2->4->6. At n=0, m=6. a[6] should be '\0'. The code sets a[2*3] = a[6] = '\0'. This part seems technically okay for termination IF the previous characters were set correctly.
        puts(a);
        return;
    }
        for(i=1;i<2*N;i+=2) // @@ The loop condition `i < 2*N` iterates through indices 1, 3, ..., 2*N-1. The value used is `(i+1)/2`, which ranges from 1 to N. This correctly iterates through numbers 1 to N. However, the variable `i` is global. In recursive calls, modifying the global `i` can cause issues when the loop resumes after recursion. The standard backtracking pattern requires the loop variable to be local to preserve its state across recursive returns. Using a global `i` here means that when `re(m+2, n-1)` returns, `i` has been modified by the deeper recursive calls, breaking the iteration in the current level.
        {
        if(b[(i+1)/2] == 0)
        {
            b[(i+1)/2] = 1;
            a[m] = (i+1)/2+'0'; // @@ This only works for single-digit numbers (1-9). If N=10, the number 10 cannot be represented by a single char `'0' + 10`. Although the problem states N<=10, this is a potential bug for N=10. However, the primary logical error causing failure for N=3 is the global loop variable.
            a[m+1] = ' ';
            re(m+2,n-1);
            b[(i+1)/2] = 0;
        }
    }
}