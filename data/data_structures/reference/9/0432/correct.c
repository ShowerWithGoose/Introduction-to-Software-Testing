#include<stdio.h>
int n;
int xn[100];
int yn[100];
int x11[100];
int y11[100];
int a[100];
px[100][6];
void mppx(int a[],int n)
{
    int i,j,hold;
    for(i=0;i<n-1;i++)
    {
      for(j=0;j<n-1-i;j++)
        if(a[j]>a[j+1])
        {
            hold=a[j];
            a[j]=a[j+1];
            a[j+1]=hold;
        }
    }
}
int main()
{
    int n,i,j=0,t=0,flag,max=0,hold,maxj;
    int b,x1,x2,y1,y2;
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        scanf("%d %d %d %d",&x1,&y1,&x2,&y2);
        px[i][1]=x1;
        px[i][2]=y1;
        px[i][3]=x2;
        px[i][4]=y2;
    }
    for(i=0;i<n-1;i++)
    {
      for(j=0;j<n-1-i;j++)
        if(px[j][1]>px[j+1][1])
        {
            hold=px[j][1];
            px[j][1]=px[j+1][1];
            px[j+1][1]=hold;
            hold=px[j][2];
            px[j][2]=px[j+1][2];
            px[j+1][2]=hold;
            hold=px[j][3];
            px[j][3]=px[j+1][3];
            px[j+1][3]=hold;
            hold=px[j][4];
            px[j][4]=px[j+1][4];
            px[j+1][4]=hold;
        }
    }
    for(i=0;i<n;i++)
    {
        flag=0;
        for(j=0;j<=t;j++)
        {
            if(px[i][1]==xn[j]&&px[i][2]==yn[j])
            {
                flag=1;
                break;
            }
        }
            if(flag==1)
            {
                a[j]++;
                xn[j]=px[i][3];
                yn[j]=px[i][4];
            }
            else
            {
                x11[t]=px[i][1];
                y11[t]=px[i][2];
                xn[t]=px[i][3];
                yn[t]=px[i][4];
                a[t]++;
                t++;
            }
    }
    for(i=0;i<n;i++)
    {
        if(max<a[i])
        {
            max=a[i];
            maxj=i;
        }
    }
    printf("%d %d %d",max,x11[maxj],y11[maxj]);


}

