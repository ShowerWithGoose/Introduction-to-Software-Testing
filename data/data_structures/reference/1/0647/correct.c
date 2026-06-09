#include<stdio.h>

    void print_permutation(int n, int *A, int cur)
    {
        if(cur == n)
        {
            for(int i=0;i<n;i++) printf("%d ",A[i]);
            printf("\n");
        }
        else
        {
            for(int i=1; i<=n; i++)
            {
                int flag=1;
                for(int j=0;j<cur;j++)
                {
                    if(A[j]==i) flag=0;
                }
                if(flag)
                {
                    A[cur]=i;
                    print_permutation(n,A,cur+1);
                }
            }
        }
    }

int main()
{
    int N;
    int A[100];
    scanf("%d",&N);
    print_permutation(N,A,0);
}
