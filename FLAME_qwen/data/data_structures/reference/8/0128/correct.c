#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
int a,b,str[102][102],temp1[102],temp2[102],flag;
void Dfs(int);
void Bfs(int);
int main()
{
    int x,y;
    scanf("%d%d",&a,&b);
    for (int i=1;i<=b;i++) //建立邻接表
    {
        scanf("%d%d",&x,&y);
        str[x][y]=1;
        str[y][x]=1;
    }
    Dfs(0);
    printf("\n");
    for (int k=0;k<102;k++)
    {
        temp1[k]=0;
        flag=0;
    }
    Bfs(0);
    printf("\n");
    for (int k=0;k<102;k++)
    {
        temp1[k]=0;
        flag=0;
    }
    scanf("%d",&x);
    temp1[x]=1;
    Dfs(0);
    printf("\n");
    for (int k=0;k<102;k++)
    {
        temp1[k]=0;
        flag=0;
    }
    temp1[x]=1;
    Bfs(0);
    printf("\n");
    for (int k=0;k<102;k++)
    {
        temp1[k]=0;
        flag=0;
    }
    return 0;
}
void Dfs(int p)
{
    if (flag==0)
    {
        flag=1;
        printf("%d",p);
    }
    else
    {
        printf(" %d",p);
    }
    temp1[p]=1;
    for (int i=1;i<=a;i++)
    {
        if (str[p][i]==1&&temp1[i]==0)
        {
            Dfs(i);
        }
    }
}
void Bfs(int p)
{
    int t;
    temp2[1]=p;
    for (int j=1,r=1;j<=r;)
    {
        t=temp2[j];
        j++;
        if (temp1[t]==1)
        {
            continue;
        }
        if (flag==0)
        {
            printf("%d",t);
            flag=1;
        }
        else
        {
            printf(" %d",t);
        }
        temp1[t]=1;
        for (int i=1;i<=a;i++)
        {
            if (str[t][i]==1&&temp1[i]==0)
            {
            	r++;
                temp2[r]=i;
            }
        }
    }
}



