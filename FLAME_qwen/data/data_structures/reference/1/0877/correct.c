#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>

int box[11],have_num[100],n;

void dfs(int step)
{
    if(step==n+1)
    {
        for(int i=1;i<=n;i++)
        {
            printf("%d ",box[i]);
        }
        printf("\n");
        return ;
    }
    
        for(int i=1;i<=n;i++)
        {
            if(have_num[i]==0)
            {
                box[step]=i;
                have_num[i]=1;
                dfs(step+1);
                have_num[i]=0;
            }
        }
        return ;
    
}

int main()
{
    scanf("%d",&n);
    dfs(1);
    system("pause");
    return 0;
}
