#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int a,b;
int str[101][101],step[101],stepp[101],flag;

void Dfs(int p)
{
    int i;
    if(flag==0)
    {
        printf("%d",p);
        flag=1;
    }
    else
        {
        printf(" %d",p);
        }
    step[p]=1;
    for(i=1;i<=a;i++)
    {
        if(str[p][i]==1&&step[i]==0)
            Dfs(i);
    }
}

void Bfs (int p)
{
    int j=1,r=1,t;
    stepp[1]=p;

    for(j=1,r=1;j<=r;)
    {
        t=stepp[j++];
        if(step[t]==1)
        {
            continue;
        }
        if(flag==0)
        {
            printf("%d",t);
            flag=1;
        }
        else{
            printf(" %d",t);
        }
        step[t]=1;
        for(int i=1;i<=a;i++)
        {
            if(str[t][i]==1&&step[i]==0)
            {
                stepp[++r]=i;
            }
        }
    }

}

int main()
{
    int x,y;
    scanf("%d%d",&a,&b);
    for(int i=1;i<=b;i++)
    {
        scanf("%d%d",&x,&y);
        str[x][y] =1;
        str[y][x] =1;
    }
    Dfs(0);
    printf("\n");
    for(int k=0;k<102;k++)
    {
        step[k]=0;
        flag=0;
    }
    Bfs(0);
    printf("\n");
    for(int k=0;k<102;k++)
    {
        step[k]=0;
        flag=0;
    }
    scanf("%d",&x);
    step[x]=1;
    Dfs(0);
    printf("\n");
    for(int k=0;k<102;k++)
    {
        step[k] = 0;
        flag =0;
    }
    step[x]=1;
    Bfs(0);
    return 0;
}








