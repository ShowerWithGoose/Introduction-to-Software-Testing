#include <stdio.h>
int a[110],b[110];
void all(int *a,int *b,int n,int d)
{
    int i;
    if(d==n+1)
    {
        for(i=1;i<=n;i++)
        {
            printf("%d",a[i]); // @@ [Missing space between numbers; output should have space-separated integers]
            
        }
        
        printf("\n");
        return; 
    }
    for(i=1;i<=n;i++)
    {
        if(b[i]==0)
        {
            b[i]=1;
            a[d]=i;
            all(a,b,n,d+1);
            b[i]=0;
        }
    }
}
int main()
{
    int n,i;
    scanf("%d",&n);
    all(a,b,n,1);
    return 0; 
}