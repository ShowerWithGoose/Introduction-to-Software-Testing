#include<stdio.h>
#include<string.h>

int  n , s[15] = {0 , 1 , 2 , 3 , 4 , 5 , 6 , 7 , 8 , 9 , 10 , 11 , 12 , 13 , 14} , ans[15] = {0 , 1 , 2 , 3 , 4 , 5 , 6 , 7 , 8 , 9 , 10 , 11 , 12 , 13 , 14} , sign[15];

void dfs(int num)
{
    int i;
    if(num==n+1)
    {
        for(i=1;i<=n;i++)
            printf("%d ",ans[i]);
        printf("\n");
        return ;
    }
    for(i=1;i<=n;i++)
    {
        if(sign[i]==0)
        {
            ans[num]=s[i];
            sign[i]=1;
            dfs(num+1);
            sign[i]=0;
        }
    }
    return ;
}
 
int main(void)
{
	scanf("%d",&n);
    memset(sign,0,sizeof(sign));
    dfs(1);
    return 0;
}


