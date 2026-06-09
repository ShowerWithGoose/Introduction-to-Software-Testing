#include<stdio.h>
int cun[10],pailie[10],mark[10];
int quanpailie(int num,int n)
{
    if(num!=n)
    {
        for(int i=0;i<n;i++) @@ // C89 does not allow declaration inside for loop
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
    for(int i=0;i<n;i++) @@ // C89 does not allow declaration inside for loop
        printf("%d",pailie[i]);
    printf("\n");
}
}
int main()
{
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;i++) @@ // C89 does not allow declaration inside for loop
    {
        cun[i]=i+1;
    }
    int num=0;
    quanpailie(num,n);
 }