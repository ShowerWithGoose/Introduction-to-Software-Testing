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
        for(i=N;i>=1;i--) @@ Iterating backwards generates permutations in reverse lexicographical order. To satisfy the lexicographical order requirement, the loop should iterate from 1 to N.
      {
        if(Mark[i]==0)
        {
            Mark[i]=1;

            a[n]=i; @@ Filling the array from index n down to 1 reverses the permutation order. Combined with the backward loop, this fails to produce lexicographically sorted output. It should fill from 1 to N (e.g., a[N-n+1]=i;).

            rank(n-1,N);

            Mark[i]=0;

        }
      }
    }

}