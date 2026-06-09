#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#define clear(a) memset(a,0,sizeof(a));
int a[11];
void again(int all,int n,int start);
void pl(int all,int n,int start);
int main()
{
    int n;
    scanf("%d",&n);
    again(n,n,1);
    pl(n,n,1);
    return 0;
}
void again(int all,int n,int start)
{
    int i;
    for(i=start;i<=all;i++)
    {
        a[i]=i;
    }
    return;
}
void pl(int all,int n,int start)
{
    int save[11],i;
    for(i=start;i<=all;i++)
    {
        save[i]=a[i];
    }
    if(n==1)
    {
        for(int i1=1;i1<=all;i1++)
        {
            printf("%d ",a[i1]);
        }
        putchar(10);
    }
    else
    {
        int i2,i3,i4,exc;
        for(i2=0;i2<n;i2++)
        {
            for(i4=start;i4<=all;i4++)
            {
                a[i4]=save[i4];
            }
            for(i3=i2;i3>0;i3--)
            {
                exc=a[start+i3];
                a[start+i3]=a[start+i3-1];
                a[start+i3-1]=exc;
            }
            pl(all,n-1,start+1);
        }
    }
    return;
}
