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
            printf("%d",a[i]); // @@ [Missing space after each number; should print "%d " instead of "%d" to match expected output format]
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