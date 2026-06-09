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
        for(i=N;i>=1;i--) // @@ [The loop iterates from N down to 1, which generates permutations in reverse lexicographical order. To produce lexicographically sorted output, the loop should iterate from 1 to N.]
      {
        if(Mark[i]==0)
        {
            Mark[i]=1;

            a[n]=i; // @@ [The array `a` is filled from index `n` downward (e.g., a[N], a[N-1], ...), which reverses the order of selected elements. To build permutations in correct order, assignment should be to `a[N - n + 1]` or similar, or the recursion should fill from the start.]

            rank(n-1,N);

            Mark[i]=0;

        }
      }
    }

}