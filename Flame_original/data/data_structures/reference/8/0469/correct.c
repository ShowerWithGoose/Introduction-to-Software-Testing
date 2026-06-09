#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
int n,m,line[120][120];
int find1[120],flag,find2[120];
void f(int x);
void g(int y);
int main()
{

    int i,j,k;
    int point1,point2;
    scanf("%d%d",&n,&m);
    for(i=0;i<m;i++)
    {
        scanf("%d%d",&point1,&point2);
        line[point1][point2]=1;
        line[point2][point1]=1;
    }
    f(0);
    printf("\n");
    memset(find1,0,sizeof(find1));
    g(0);
    printf("\n");
    scanf("%d",&j);
    find1[j]=1;
    f(0);
    printf("\n");
    memset(find1,0,sizeof(find1));
    find1[j]=1;
    g(0);
    printf("\n");
    return 0;
}
void f(int x)
{
    int i;
    printf("%d ",x);
    find1[x]=1;
    for(i=1;i<=n;i++)
    {
        if(line[x][i])
        {
            if(find1[i]==0)
            {
                f(i);
            }
        }
    }
}
void g(int y)
{
    find2[1]=y;
    int l=1,r=1,i;
    while(l<=r)
    {
        int a=find2[l];
        l++;
        if(find1[a])
        {
            continue;
        }
        printf("%d ",a);
        find1[a]=1;
        for(i=1;i<=n;i++)
        {
            if(line[a][i])
            {
                if(find1[i]==0)
                {
                    find2[++r]=i;
                }
            }
        }
    }
    memset(find1,0,sizeof(find1));
}

