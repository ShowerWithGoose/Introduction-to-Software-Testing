#include<stdio.h>
int line[105][4],flag[105],point[105][2];
void bubble(int[],int[][2],int);
int main()
{
    int n,i,j=0,h,g;
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        scanf("%d%d%d%d",&line[i][0],&line[i][1],&line[i][2],&line[i][3]);
    }
    for(i=0;i<n;i++)
    {
        g=i;
        for(h=0;h<n;h++)
        {
            if(line[g][2]==line[h][0]&&line[g][3]==line[h][1])
            {
                flag[j]++;
                g=h;
                h=-1;
                if(point[j][0]==0)
                {
                    point[j][0]=line[i][0];
                    point[j][1]=line[i][1];
                }
            }
        }
        j++;
    }
    /*for(i=0;i<j;i++)
    {
        printf("%d\n",flag[i]);
    }*/
    bubble(flag,point,j);
    /*for(i=0;i<j;i++)
    {
        printf("%d\n",flag[i]);
    }*/
    printf("%d %d %d",flag[j-1]+1,point[j-1][0],point[j-1][1]);
    return 0;
}
void bubble(int a[],int point[][2],int n)
{
    int i,j,hold1,hold2,hold3,flag;
    for(i=0;i<n-1;i++)
    {
        flag=0;
        for(j=0;j<n-1-i;j++)
        {
            if(a[j]>a[j+1])
            {
                hold1=a[j],hold2=point[j][0],hold3=point[j][1];
                a[j]=a[j+1],point[j][0]=point[j+1][0],point[j][1]=point[j+1][0];
                a[j+1]=hold1,point[j+1][0]=hold2,point[j+1][1]=hold3;
                flag=1;
            }
        }
        if (0==flag)
        break;
    }
}


