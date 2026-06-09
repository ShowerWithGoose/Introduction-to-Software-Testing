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
            else {printf("%d\n",a[i]);} // @@ Missing trailing space; expected output includes a space after the last integer.
        }

        return ;
    }

    else if(n>0)
    {
        for(i=N;i>=1;i--) // @@ Loop iterates from N to 1, causing permutations to be generated in non-lexicographic order for N>2; should iterate from 1 to N and fill from the first position to achieve lexicographic order.
      {
        if(Mark[i]==0)
        {
            Mark[i]=1;

            a[n]=i;

            rank(n-1,N);

            Mark[i]=0;

        }
      }
    }

}