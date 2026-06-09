#include<stdio.h>
int cun[10],pailie[10],mark[10];
int quanpailie(int num,int n) // @@ Function does not return a value, should be declared as void to avoid undefined behavior or compilation warnings.
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
        printf("%d",pailie[i]); // @@ Missing space separator between integers. The output format requires each integer in a line to be separated by a space.
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