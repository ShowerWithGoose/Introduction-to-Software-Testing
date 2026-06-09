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
            else {printf("%d\n",a[i]);} // @@ This line prints the last integer without a trailing space. The reference program prints a space after every integer, including the last, which is expected by the judge (as seen in the test case's expected output). To match the required output format, a space should also be printed before the newline, or the loop should print a space after each number and then a newline outside the loop.
        }

        return ;
    }

    else if(n>0)
    {
        for(i=N;i>=1;i--) // @@ This descending loop generates permutations in reverse lexicographic order for N > 2, violating the requirement that output lines be sorted lexicographically. The loop should iterate from 1 to N (ascending) to produce permutations in correct lexicographic order.
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