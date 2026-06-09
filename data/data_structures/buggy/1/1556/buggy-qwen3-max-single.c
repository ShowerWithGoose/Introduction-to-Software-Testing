#include <stdio.h>
    int Mark[11];
    int M[11];
    int jiecheng(int n); // @@ [This function is declared but never defined or used, though it doesn't cause a compilation error by itself. However, the real issue is elsewhere.]
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
            for(int i=1;i<n;i++) // @@ [Loop runs from 1 to n-1, but array M is filled starting from index 1 to n. This misses printing M[n] in the loop and then prints it separately, which is okay logically, but the bigger issue is that the output format requires space separation, not direct concatenation.]
            {
                printf("%d",M[i]); // @@ [Missing space after each number; should be "%d " to match expected output format. This causes formatting error, but not compilation error. However, the reported error is "gcc: not found", which is not a code error. But since the problem states "Compilation Error" and provides this source, we must assume the environment issue is misleading and focus on logical/syntactic errors that could cause real compilation issues in standard C.]
            }
            printf("%d\n",M[n]);
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