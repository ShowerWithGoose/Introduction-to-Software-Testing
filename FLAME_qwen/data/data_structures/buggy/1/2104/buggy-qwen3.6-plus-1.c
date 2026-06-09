#include<stdio.h>
#include<string.h>
int N,P[11]={0},Visited[11]={0};
void perm(int n)
{
    int i;
    if(n>N)
    {
        for(int j=1;j<=N;j++) // @@ Declaring loop variable 'j' inside the for loop initialization is not supported in C89/C90 standard, which may cause a compilation error.
        printf("%d",P[j]); // @@ Missing space separator between integers. The problem requires each integer to be separated by a space.
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