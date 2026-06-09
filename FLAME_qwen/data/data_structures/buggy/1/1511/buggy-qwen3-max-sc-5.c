#include<stdio.h>
int a[11];
int Mark[11]={0};
void rank(int,int);
int main()
{
    int N;

    scanf("%d",&N);

    rank(N,N); // @@ [The function call starts filling the permutation from the last position (index N) downward, and iterates i from N to 1, which generates permutations in reverse lexicographical order. The problem requires lexicographical order, so the loop should iterate from 1 to N and fill positions from 1 upward.]

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
        for(i=N;i>=1;i--) // @@ [This loop iterates from N down to 1, causing larger numbers to be placed earlier in the recursion, which results in permutations being generated in reverse lexicographical order. To produce lexicographical order, it should iterate from 1 to N.]
      {
        if(Mark[i]==0)
        {
            Mark[i]=1;

            a[n]=i; // @@ [Because the recursion starts at position n = N and decrements, and we're assigning larger i values first due to the loop direction, the resulting array a is filled from the end with larger numbers first, breaking lexicographical ordering.]

            rank(n-1,N);

            Mark[i]=0;

        }
      }
    }

}