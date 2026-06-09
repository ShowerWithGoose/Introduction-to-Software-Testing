#include <stdio.h>

int tmp1[103] = {0};
int tmp2[103] = {0};
int point,side,ex[111][111];
int flag = 0;

void qpow1(int t)
{
    if(flag == 0)
    {
        printf("%d",t);
        flag = 1;
    }
    else
    {
        printf(" %d",t);
    }
    tmp1[t] = 1;
    for(int i = 1;i<=point;i++)
    {
        if(ex[t][i] == 1&&tmp1[i]==0)
        {
            qpow1(i);
        }
    }
    return;
}

void qpow2(int t)
{
    int yyy;
    tmp2[1] = t;
    for(int i = 1,j = 1;i<=j;)
    {
        yyy = tmp2[i++];
        if(tmp1[yyy] == 1)
        {
            continue;
        }

        if(flag == 0)
        {
            printf("%d",yyy);
            flag = 1;
        }
        else
        {
            printf(" %d",yyy);
        }
        tmp1[yyy] = 1;
        for(int u = 1;u<=point;u++)
        {
            if(ex[yyy][u] == 1&&tmp1[u] == 0)
            {
                tmp2[++j] = u;
            }
        }
    }
    return;
}

int main()
{
    int a,b;
    int del;
    scanf("%d %d",&point,&side);

    for(int i = 0;i<side;i++)
    {
        scanf("%d %d",&a,&b);
        ex[a][b] = 1;
        ex[b][a] = 1;
    }
    qpow1(0);
    printf("\n");
    for(int i = 0; i<102;i++)
    {
        tmp1[i] = 0;
    }
    flag = 0;

    qpow2(0);
    printf("\n");
    for(int i = 0; i<102;i++)
    {
        tmp1[i] = 0;
    }
    flag = 0;

    scanf("%d",&del);

    tmp1[del] = 1;

    qpow1(0);
    printf("\n");
    for(int i = 0; i<102;i++)
    {
        tmp1[i] = 0;
    }
    tmp1[del] = 1;
    flag = 0;

    qpow2(0);
    printf("\n");
    for(int i = 0; i<102;i++)
    {
        tmp1[i] = 0;
    }
    flag = 0;
    tmp1[del] = 1;

    return 0;
}

