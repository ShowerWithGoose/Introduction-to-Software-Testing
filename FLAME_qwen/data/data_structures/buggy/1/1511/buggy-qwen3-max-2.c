#include<stdio.h>
int a[11];
int Mark[11]={0};
void rank(int,int);
int main()
{
    int N;

    scanf("%d",&N);

    rank(N,N); // @@ [The function call starts filling the permutation from position N down to 1, but it iterates i from N down to 1 in the loop, which produces permutations in reverse lexicographical order instead of lexicographical order.]

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
        for(i=N;i>=1;i--) // @@ [Looping from N down to 1 causes larger numbers to be tried first at each position, resulting in permutations generated in reverse lexicographical order. To produce lexicographical order, the loop should iterate from 1 to N.]
      {
        if(Mark[i]==0)
        {
            Mark[i]=1;

            a[n]=i; // @@ [Assigning the selected number to position 'n' (which starts at N and decreases) means the first chosen number goes to the last position of the array, reversing the intended order of the permutation.]

            rank(n-1,N);

            Mark[i]=0;

        }
      }
    }

}