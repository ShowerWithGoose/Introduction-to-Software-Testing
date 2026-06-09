#include<stdio.h>
#include<string.h>
int N,P[11]={0},Visited[11]={0};
void perm(int n)
{
    int i;
    if(n>N)
    {
        for(int j=1;j<=N;j++)
        printf("%d",P[j]); // @@ [Missing space after %d; should be printf("%d ",P[j]); to separate numbers by spaces]
        printf("\n");
        return;
    }
    for(i=1;i<=N;i++)
    if(Visited[i]==0){
        Visited[i]=1;
        P[n]=i;
        perm(n+1);
        Visited[i]=0;
    }
}
int main()
{
    scanf("%d",&N);
    perm(1);
    return 0;
}