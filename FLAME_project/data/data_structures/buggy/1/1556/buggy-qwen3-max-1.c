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
                printf("%d",M[i]);
            }
            printf("%d\n",M[n]); // @@ [The output format is incorrect: numbers should be separated by spaces, but this prints them concatenated without spaces. Also, the loop prints M[1] to M[n-1] without space after each, and then M[n] with newline, causing missing space between last two numbers.]
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