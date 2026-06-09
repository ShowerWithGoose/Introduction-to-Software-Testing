#include<stdio.h> 
#include<stdlib.h>
#include<string.h>
#include<math.h>
int i,j,k,m,nx,ny,nz,flag,nsum,temp0,temp1;
char a[10000],b[10000],c;
int x[1000][2],y[1000][2],z[1000][2],sum[1000][2];
int main()
{  while(1)
  {
    scanf("%d%d%c",&x[i][0],&x[i][1],&c);
    if(c==' ')
    {
        i++;
        nx++;
        continue;
    }
    else if(c=='\n')
    {
       nx++;
       break;
    }
  }
  i=0;
  while(1)
  {
    scanf("%d%d%c",&y[i][0],&y[i][1],&c);
    if(c==' ')
    {
        i++;
        ny++;
        continue;
    }
    else if(c=='\n')
    {
        ny++;
        break;
    }
  }
   for(i=0;i<nx;i++)
   {
       for(j=0;j<ny;j++)
       {
           z[k][0]=x[i][0]*y[j][0];
           z[k][1]=x[i][1]+y[j][1];
           k++;
           nz++;
       }
   }
   k=0;
   for(i=0;i<nz;i++)
   {
       for(j=i+1;j<nz;j++)
       {
           if(z[i][1]==z[j][1]&&z[i][1]>=0&&z[j][1]>=0)
           {
               flag=0;
               z[i][0]+=z[j][0];
               z[j][1]=-1;
           }                  
           else if(z[i][1]!=z[j][1]&&z[i][1]>=0&&z[j][1]>=0)
           {
               flag=1;
           }
       }
       
       if(flag==1&&z[i][1]>=0)
       {
           sum[k][0]=z[i][0];
           sum[k][1]=z[i][1];
           k++;
           nsum++;
       }
       else if(flag==0&&z[i][1]>=0)
       {
           sum[k][0]=z[i][0];
           sum[k][1]=z[i][1];
           k++;
           nsum++;
       }
   }
   //接下来对sum排序
   for(i=0;i<nsum;i++)
   {
       for(j=i+1;j<nsum;j++)
       {
           if(sum[i][1]<sum[j][1])
           {
               temp0=sum[i][0];
               sum[i][0]=sum[j][0];
               sum[j][0]=temp0;
               temp1=sum[i][1];
               sum[i][1]=sum[j][1];
               sum[j][1]=temp1;
           }
       }
   }
   for(i=0;i<nsum;i++)
   printf("%d %d ",sum[i][0],sum[i][1]);


   system("pause");
   return 0;
}

