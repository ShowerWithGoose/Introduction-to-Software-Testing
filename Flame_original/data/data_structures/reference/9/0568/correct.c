#include <stdio.h>
int i,j,k,N,flag,max=0,mid,a[205]={0},b[3][205]={0},c[3][205]={0};
int main()
{

    scanf("%d",&N);
    for(i=0;i<N;i++)
    {
        scanf("%d%d%d%d",&b[1][i],&b[2][i],&c[1][i],&c[2][i]);
        a[i]=1;
    }
/*for(i=0;i<N;i++)
    {
        printf("%d %d %d %d\n",b[1][i],b[2][i],c[1][i],c[2][i]);
        a[i]=1;
    }
    printf("\n");*/

    k=1;
    for(i=0;i<N;i++)
    {
        for(j=0;j<N-i-1;j++)
        {     if(b[1][j]>b[1][j+1])
              {  int temp=b[1][j];
              b[1][j]=b[1][j+1];
              b[1][j+1]=temp;

                temp=b[2][j];
              b[2][j]=b[2][j+1];
              b[2][j+1]=temp;

               temp=c[1][j];
              c[1][j]=c[1][j+1];
              c[1][j+1]=temp;

              temp=c[2][j];
              c[2][j]=c[2][j+1];
              c[2][j+1]=temp;
              }

        }

    }
   /*printf("%d\n",N);
     for(i=0;i<N;i++)
    {
        printf("%d %d %d %d\n",b[1][i],b[2][i],c[1][i],c[2][i]);
        a[i]=1;
    }*/

        for(i=0;i<N;i++)
    {flag=0;
        for(j=i+1;j<N;j++)
        {     if(c[1][i]==b[1][j]&&c[2][i]==b[2][j])
             {   flag=1;
                 a[i]++;
                 c[1][i]=c[1][j];
                 c[2][i]=c[2][j];
                 for(k=j;k<N-1;k++)
                 {
                     b[1][k]=b[1][k+1];
                     b[2][k]=b[2][k+1];
                     c[1][k]=c[1][k+1];
                     c[2][k]=c[2][k+1];
                 }
                 N--;

             }
        }

        if(flag==1)
        {
            i--;
        }
    }
for(i=0;i<N;i++)
{
    if(a[i]>max)
    {
        max=a[i];
        mid=i;
    }
}
printf("%d %d %d",max,b[1][mid],b[2][mid]);
return 0;}

