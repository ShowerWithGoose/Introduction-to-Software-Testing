#include<stdio.h>
int cun[10],pailie[10],mark[10];
int quanpailie(int num,int n) // @@ Function declared to return int but lacks a return statement, causing compilation warning/error. Change return type to void.
{
    if(num!=n)
    {
        for(int i=0;i<n;i++) // @@ Declaring loop variable inside for statement is invalid in C89/C90, causing compilation error. Declare int i at the beginning of the block.
        {
            if(mark[i]==0)
            {
                pailie[num]=cun[i];
                mark[i]=1;
                quanpailie(num+1,n);
                mark[i]=0;
            }
        }
    }
    else
    {
    for(int i=0;i<n;i++) // @@ Same C89 compilation error: loop variable declaration inside for is not allowed.
        printf("%d",pailie[i]); // @@ Missing space separator between output numbers, violating the required output format.
    printf("\n");
}
}
int main()
{
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;i++) // @@ Same C89 compilation error: loop variable declaration inside for is not allowed.
    {
        cun[i]=i+1;
    }
    int num=0; // @@ In C89, variables must be declared at the top of the block before any statements, causing compilation error.
    quanpailie(num,n);
 }