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
        for(i=N;i>=1;i--) // @@ This loop iterates from N down to 1, which generates permutations in reverse lexicographical order. To produce lexicographically sorted output (smaller numbers first), the loop should iterate from 1 to N.
      {
        if(Mark[i]==0)
        {
            Mark[i]=1;

            a[n]=i; // @@ The array index n is used to store the current number, but n starts at N and decreases. This stores numbers from the end of the array, causing the output order to be reversed. To match the expected lexicographic order, the index should start from 1 and increase (e.g., a[N-n+1]=i).

            rank(n-1,N);

            Mark[i]=0;

        }
      }
    }

}