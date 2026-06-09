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
                printf("%d",M[i]); // @@ Error: Missing space between numbers. Should be "%d " to match expected output format with spaces.
            }
            printf("%d\n",M[n]); // @@ Error: Missing space before the last number. Should be "%d\n" but the loop above should print spaces, so this line should be "%d\n" only if the loop prints spaces correctly.
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