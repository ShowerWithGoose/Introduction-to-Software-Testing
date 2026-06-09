#include<stdio.h>
int cun[10],pailie[10],mark[10];
int quanpailie(int num,int n)
{
    if(num!=n)
    {
        for(int i=0;i<n;i++)
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
    for(int i=0;i<n;i++)
        printf("%d",pailie[i]);
    printf("\n");
}
} // @@ [Function definition is missing a return statement for non-void function; also, the output format requires spaces between numbers and lexicographical order may not be guaranteed due to loop starting at 0 without ensuring sorted input usage]
int main()
{
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        cun[i]=i+1;
    }
    int num=0;
    quanpailie(num,n); // @@ [The function quanpailie is declared to return int but does not return a value in all paths, which causes undefined behavior and may lead to compilation warnings or errors depending on compiler settings]
 }