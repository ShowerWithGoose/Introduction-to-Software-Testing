#include<stdio.h>
int a[11];
int Mark[11]={0};
int N;
void rank(int,int);
int main()
{
    scanf("%d",&N);

    rank(0,N);

    return 0;
}

void rank(int M,int n)
{
    int i;

    if(n==0)
    {
        for(i=0;i<N;i++)
        {
            if(i!=N-1){printf("%d ",a[i]);}
            else {printf("%d\n",a[i]);}

        }

        return ;
    }

    else if(n>0)
    {
        for(i=1;i<=N;i++)
      {
        if(Mark[i]==0)
        {
            Mark[i]=1;

            a[M]=i;

            rank(M+1,n-1);

            Mark[i]=0;

        }
      }
    }

}

