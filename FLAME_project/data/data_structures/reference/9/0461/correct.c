#include <stdio.h>
#include <stdlib.h>
int main()
{
    int line[100][4],zuobiao[100][4],num[100];
    int n,max=0;
    int i,j,a,e,flag=0;
    int h=0;
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        for(j=0;j<4;j++)
        {
            scanf("%d",&line[i][j]);
        }
    }
    for(i=0;i<n;i++)
    {
        e=i;
        for(j=0;j<n;j++)
        {
            if(j==e)
                continue;
            else if(line[j][2]==line[i][0]&&line[j][3]==line[i][1]&&j!=e)
            {
                flag=1;
                break;
            }
        }
        if(flag==0)
        {
            zuobiao[h][0]=line[i][0];
            zuobiao[h][1]=line[i][1];
            zuobiao[h][2]=line[i][2];
            zuobiao[h][3]=line[i][3];
            h++;
        }
        flag=0;
    }
    for(i=0;i<h;i++)
    {
        num[i]=1;
        for(j=0;j<n;j++)
        {
            if(zuobiao[i][2]==line[j][0]&&zuobiao[i][3]==line[j][1])
            {
                zuobiao[i][2]=line[j][2];
                zuobiao[i][3]=line[j][3];
                num[i]++;
                j=-1;
            }
        }
    }
    for(i=0;i<h;i++)
    {
        if(max<num[i])
        {
            max=num[i];
            a=i;
        }
    }
    printf("%d %d %d",max,zuobiao[a][0],zuobiao[a][1]);

    return 0;
}

