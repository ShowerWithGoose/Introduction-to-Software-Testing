#include<stdio.h>
int cun[10],pailie[10],mark[10];
int quanpailie(int num,int n) // @@ Function declared as int but has no return statement; should be void to avoid undefined behavior.
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
        printf("%d",pailie[i]); // @@ Missing spaces between numbers; expected output format requires spaces (e.g., "1 2 3").
    printf("\n");
}
}
int main()
{
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        cun[i]=i+1;
    }
    int num=0;
    quanpailie(num,n);
 }