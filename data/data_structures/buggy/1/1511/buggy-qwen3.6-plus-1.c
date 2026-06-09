#include<stdio.h>
int a[11];
int Mark[11]={0};
void rank(int,int);
int main()
{
    int N;

    scanf("%d",&N);

    rank(N,N); // @@ Error: Initial call should start from index 1 (e.g., rank(1, N)) to fill permutations from left to right for lexicographical order.

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
        for(i=N;i>=1;i--) // @@ Error: Iterating from N down to 1 generates permutations in reverse/non-lexicographical order; should iterate from 1 to N.
      {
        if(Mark[i]==0)
        {
            Mark[i]=1;

            a[n]=i; // @@ Error: Filling the array from the last index downwards disrupts lexicographical ordering; should fill from index 1 upwards.

            rank(n-1,N); // @@ Error: Decreasing the index fills the array backwards; should increment the index (e.g., rank(n+1, N)) to fill forwards.

            Mark[i]=0;

        }
      }
    }

}