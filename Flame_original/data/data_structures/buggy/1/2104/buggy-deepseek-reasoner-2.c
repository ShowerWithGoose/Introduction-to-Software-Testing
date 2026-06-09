#include<stdio.h>
#include<string.h>
int N,P[11]={0},Visited[11]={0};
void perm(int n)
{
    int i;
    if(n>N)
    {
        for(int j=1;j<=N;j++) // @@ Compilation error: variable declaration inside for loop not allowed in C89 (C99 feature).
        printf("%d",P[j]);
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