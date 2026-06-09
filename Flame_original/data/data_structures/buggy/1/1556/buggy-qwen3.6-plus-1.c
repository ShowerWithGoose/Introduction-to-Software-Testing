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
        for(int i=1;i<n;i++) // @@ Declaring a loop variable inside the for loop initialization is not supported in the C89/C90 standard, which causes a compilation error on strict compilers.
        {
            printf("%d",M[i]); // @@ Missing space separator between integers, violating the output format requirement.
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