#include<stdio.h>
#include<string.h>
#include<math.h> 
int a[1000],b[1000],n;
void dfs(); 
int main()
{
    scanf("%d",&n); 
    dfs(1);
    return 0;
}
void dfs(int step)
{
    int i;
    for(i=1;i<=n;i++)
    {
        if (b[i]==0)  
        {
            
            b[i]=1;  
            a[step]=i;  
            dfs(step+1);  
            b[i] = 0;  
        }
    }
    if(step==n+1)  
    {   
        for(i=1;i<=n;i++)
        {
            printf("%d ",a[i]);
        }
        printf("\n");
        return;
    }
    return;
}






