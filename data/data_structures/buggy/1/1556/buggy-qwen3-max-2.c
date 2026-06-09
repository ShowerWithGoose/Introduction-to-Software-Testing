#include <stdio.h>
    int Mark[11];
    int M[11];
    int jiecheng(int n); // @@ [Declaration of unused function 'jiecheng' is unnecessary but not an error; however, the real issue is missing function prototype for 'mark' before use in main if compiled in strict mode, but more critically: output format is wrong—missing spaces between numbers]
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
            for(int i=1;i<n;i++)
            {
                printf("%d",M[i]); // @@ [Missing space after each number except the last; should print "%d " to match expected output format]
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