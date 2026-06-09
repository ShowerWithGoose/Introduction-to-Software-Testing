#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
#include<ctype.h>
int a,b,lin[101][101],jilu[101],jilu0[101];
int f;
void deep(int p)
{
    printf("%d ",p);
    jilu[p]=1;
    for(int i=1;i<=a;i++)
    {
        if(lin[p][i]==1 && jilu[i]!=1)
        {
            deep(i);
        }
    }
}
void wide(int p)
{
    int t;
    jilu0[1]=p;
    for(int i=1,r=1;i<=r;)
    {
        t=jilu0[i++];
        if(jilu[t]==1)
        {
            continue;
        }
        printf("%d ",t);
        jilu[t]=1;
        for(int j=1;j<=a;j++)
        {
            if(lin[t][j]==1 && jilu[j]==0)
                jilu0[++r]=j;
        }
    }
}
int main()
{
    scanf("%d%d",&a,&b);
    int x,y,p=0;
    for(int i=0;i<b;i++)
    {
        scanf("%d%d",&x,&y);
        lin[x][y]=1;
        lin[y][x]=1;
    }
    deep(p);
    printf("\n");
    memset(jilu,0,sizeof(jilu));
    wide(p);
    printf("\n");
    memset(jilu,0,sizeof(jilu));
    scanf("%d",&x);
    for(int i=0;i<a;i++)
    {
        lin[x][i]=0;
        lin[i][x]=0;
    }
    deep(p);
    printf("\n");
    memset(jilu,0,sizeof(jilu));
    wide(p);
    printf("\n");
    memset(jilu,0,sizeof(jilu));

}

