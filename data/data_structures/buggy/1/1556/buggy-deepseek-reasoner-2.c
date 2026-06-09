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
            for(int i=1;i<n;i++)
            {
                printf("%d",M[i]); // @@ [Missing space after number; should be "%d " to separate integers by spaces as required]
            }
            printf("%d\n",M[n]); // @@ [Missing space before the last number; should be " %d\n" or adjust loop to print all numbers with spaces inside]
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