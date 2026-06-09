#include<stdio.h>
#include<string.h>
#include<math.h>
#include<stdlib.h>
#include<ctype.h>
void sort(int a[101][4],int n,int b[4]);
int a[101][4],b[4],n,max=0,num,x,y;
int main()
{
    int i,j,k;
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        scanf("%d %d %d %d",&a[i][0],&a[i][1],&a[i][2],&a[i][3]);
    }
    sort(a,n,b);
    for(i=0;i<n;i++)
    {
        k=i;
        num=0;
        for(j=i+1;j<n;j++)
        {
            if(a[k][2]==a[j][0]&&a[k][3]==a[j][1])
            {
                k=j;
                num++;
            }
        }
        if(num>max)
        {
            max=num;
            x=a[i][0];
            y=a[i][1];
        }
    }
    printf("%d %d %d",max+1,x,y);
    return 0;
}
void sort(int a[101][4],int n,int b[4])
{
   for(int i=0;i<n;i++)
   {
       for(int j=i+1;j<n;j++)
       {
           if(a[i][0]>a[j][0])
           {
               for(int k=0;k<4;k++)
               {
                   b[k]=a[i][k];
               }
               for(int k=0;k<4;k++)
               {
                   a[i][k]=a[j][k];
               }
               for(int k=0;k<4;k++)
               {
                   a[j][k]=b[k];
               }
           }
       }
   }
}


