#include<stdio.h>
int a[11];
int Mark[11]={0};
void rank(int,int);
int main()
{
    int N;

    scanf("%d",&N);

    rank(N,N); // @@ [The function call starts filling the permutation from position N down to 1, but it iterates i from N down to 1, which generates permutations in reverse lexicographical order. The problem requires lexicographical order.]

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
        for(i=N;i>=1;i--) // @@ [Looping from N down to 1 causes larger numbers to be placed earlier in the recursion, resulting in permutations being generated in reverse lexicographical order instead of the required lexicographical order. It should loop from 1 to N.]
      {
        if(Mark[i]==0)
        {
            Mark[i]=1;

            a[n]=i; // @@ [Assigning to a[n] where n starts at N and decreases means the last position in the array is filled first. Combined with the descending loop, this breaks lexicographical ordering. The recursion should fill positions from 1 upward (like in the reference program) to maintain correct order.]

            rank(n-1,N);

            Mark[i]=0;

        }
      }
    }

}