#include<stdio.h>
void dfs(int );
int a[11],b[11];
int n;
int main()
{
    scanf("%d",&n);
    dfs(1);
    return 0;
}
void dfs(int step)
{int i;

    if(step>n)
    {

        for(i=1; i<=n; i++)
        {
            printf("%d",a[i]); // @@ The output format requires integers to be separated by a space, but this line prints them consecutively without spaces. It should be printf("%d ", a[i]); or similar logic to handle spacing correctly.
        }
        printf("\n");
        return;

    }
    for(i=1; i<=n; i++)
    {
        if(b[i]==0)
                {a[step]=i;
                b[i]=1;
                dfs(step+1);
                b[i]=0;}
       }


   }