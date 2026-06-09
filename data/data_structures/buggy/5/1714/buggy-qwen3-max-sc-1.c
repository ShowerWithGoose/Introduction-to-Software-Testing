#include<stdio.h>
int x[100][2],y[100][2],z[10000][2],ans[10000][2];
void bubble(int n)
{
    int i,j,hold[2],flag;
    for(i=0;i<n-1;i++)
    {
        flag=0;
        for(j=0;j<n-1-i;j++)
        {
            if(z[j][1]<z[j+1][1])
            {
                hold[0]=z[j][0];
                z[j][0]=z[j+1][0];
                z[j+1][0]=hold[0];
                hold[1]=z[j][1];
                z[j][1]=z[j+1][1];
                z[j+1][1]=hold[1];
                flag=1;
            }
        }
        if (0==flag)
            break;
    }
}

int main()
{
    int i,j=0,k=0,l=0,countx,county;
    char c;
    scanf("%d %d",&x[0][0],&x[0][1]);
    scanf("%c",&c);
    for(i=1;c!='\n';i++)
    {
        scanf("%d %d",&x[i][0],&x[i][1]);
        scanf("%c",&c);
    }
    countx=i; @@ [The loop condition `c!='\n'` uses uninitialized `c` on first iteration if input has only one term; also, after reading the last term, `scanf("%c",&c)` may read a space instead of newline due to format mismatch, causing incorrect loop termination or infinite loop.]
    while(scanf("%d%d",&y[j][0],&y[j][1])!=EOF)
    {
        j++;
    }
    county=j;
    for(i=0;i<countx;i++)
    {
        for(j=0;j<county;j++)
        {
            z[k][0]=x[i][0]*y[j][0];
            z[k][1]=x[i][1]+y[j][1];
            k++;
        }
    }
    bubble(k);
    for(i=0;i<k;i++)
    {
        if(z[i+1][1]!=z[i][1])
        {
            ans[l][0]=z[i][0];
            ans[l][1]=z[i][1];
            l++;
        }
        else
        {
            ans[l][1]=z[i][1];
            for(j=i;z[j][1]==z[i][1];j++)
                ans[l][0]+=z[j][0]; @@ [Variable `ans[l][0]` is used uninitialized; it should be initialized to 0 before accumulation. Also, loop may access `z[j]` beyond array bounds when `j` reaches `k`.]
            i=j;
            l++;
        }
    }
    for(i=0;i<l;i++)
        printf("%d %d ",ans[i][0],ans[i][1]);
    return 0;
}