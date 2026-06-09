#include <stdio.h>
    int Mark[11];
    int M[11];
    int jiecheng(int n); // @@ [This function is declared but never defined or used, which may cause a linker error if called; however, since it's unused, this alone wouldn't cause a compilation error. The actual issue is likely elsewhere.]
    void mark(int n,int k);
    int main()
    {
        int N;
        scanf("%d",&N);
        mark(N,N);
        return 0;
    }
    void mark(int n,int k)
    {
        if(k==0)
        {
            for(int i=1;i<n;i++) // @@ [Loop runs from 1 to n-1, then prints M[n] separately. This causes permutations to be printed with numbers from M[1] to M[n], but array M is filled starting at index 1 (M[n-k+1] when k=n gives M[1]). However, the bigger issue: using 'int i=1' in for-loop initializer requires C99 or later. If compiler defaults to older standard (like C89), this causes a compilation error.]
            {
                printf("%d",M[i]);
            }
            printf("%d\n",M[n]);
        }
        else
        {
            int i=0; // @@ [This declaration is redundant because 'i' is redeclared in the for-loop below as 'int i=1', which is invalid in C89/C90 where all variables must be declared at the beginning of a block. Mixing declarations and code like this causes a compilation error in pre-C99 standards.]
            for(i=1; i<=n; i++) // @@ [In C89/C90, declaring 'int i=1' here is invalid because variable declarations must precede all statements in a block. The earlier 'int i=0;' is legal, but redeclaring 'i' in the for-loop initializer is not allowed in older C standards, leading to a compilation error.]
            {
                if(Mark[i] == 0)
                {
                    Mark[i] = 1;
                    M[n-k+1]=i;
                    mark(n,k-1);
                    Mark[i] = 0;
                }
            }
        }
        
        
        
        
        
        
        
        
        
    }