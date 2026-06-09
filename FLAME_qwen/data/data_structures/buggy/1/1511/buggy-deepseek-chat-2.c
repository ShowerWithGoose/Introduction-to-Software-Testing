#include<stdio.h>
int a[11];
int Mark[11]={0};
void rank(int,int);
int main()
{
    int N;

    scanf("%d",&N);

    rank(N,N);

    return 0;
}

void rank(int n,int N)
{
    int i;

    if(n==0)
    {
        for(i=1;i<=N;i++)
        {
            if(i!=N){printf("%d ",a[i]);}
            else {printf("%d\n",a[i]);}

        }

        return ;
    }

    else if(n>0)
    {
        for(i=N;i>=1;i--) // @@ The loop iterates from N down to 1, which generates permutations in reverse lexicographical order (largest first) instead of the required lexicographical order (smallest first). To fix, iterate from 1 to N.
      {
        if(Mark[i]==0)
        {
            Mark[i]=1;

            a[n]=i; // @@ Assigning i to a[n] when n counts down from N to 1 reverses the order of elements in the permutation array, causing the output to be in reverse order. To match the reference program, assign to a[m] where m counts up from 1.

            rank(n-1,N);

            Mark[i]=0;

        }
      }
    }

}