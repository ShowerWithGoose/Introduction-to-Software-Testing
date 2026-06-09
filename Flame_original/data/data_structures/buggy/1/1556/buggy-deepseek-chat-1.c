#include <stdio.h>
    int Mark[11];
    int M[11];
    int jiecheng(int n);
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
            for(int i=1;i<n;i++) // @@ Error: The loop condition should be i <= n to print all N elements, but here it stops at n-1, missing the last element. Also, the final printf prints M[n] separately, but if n is the total number of elements (N), then M[n] is out of bounds because arrays are 0-indexed and M is declared as M[11], so M[N] is valid only if N <= 10, but the logic is inconsistent with the loop.
            {
                printf("%d",M[i]);
            }
            printf("%d\n",M[n]); // @@ Error: This prints M[n] which is the last element, but the loop above prints M[1] to M[n-1]. However, if n is the original N, then M[n] is the N-th element (index N), which is valid only if N <= 10. But the loop should include all elements from 1 to n, so the correct approach is to loop i from 1 to n and print M[i] each time, without a separate final print.
        }
        else
        {
            int i=0;
            for(i=1; i<=n; i++)
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