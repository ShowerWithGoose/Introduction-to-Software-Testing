#include<stdio.h>
#include<string.h>
#include<math.h>
#include<stdlib.h>
 int line[100][5];
int main()
{
   int n,f=0,m,max=0,mx,my,cx,cy,num=0;
   scanf("%d",&n);
   for(int i=0;i<n;i++)
 {
     scanf("%d%d%d%d",&line[i][0],&line[i][1],&line[i][2],&line[i][3]);
     line[i][4]=1;
 }
       for(int i=1;i<n;i++)
       {
          f=0;
        for(int j=0;j<n-i;j++)
          if(line[j][0]>line[j+1][0])
          {
              m=line[j][0];
              line[j][0]=line[j+1][0];
              line[j+1][0]=m;
              m=line[j][1];
              line[j][1]=line[j+1][1];
              line[j+1][1]=m;
              m=line[j][2];
              line[j][2]=line[j+1][2];
              line[j+1][2]=m;
              m=line[j][3];
              line[j][3]=line[j+1][3];
              line[j+1][3]=m;
              f=1;
          }
          if(f==0)
            break;
       }
       for(int i=0;i<n;i++)
       {
           num=1;
           if(line[i][4]==1)
           {
            cx=line[i][2];
            cy=line[i][3];
            for(int j=i+1;j<n;j++)
            if(line[j][4]&&line[j][0]==cx&&line[j][1]==cy)
            {
                        line[j][4]=0;
                        cx=line[j][2];
                        cy=line[j][3];
                        num++;
            }
            line[i][4]=0;
            if(num>max)
            {
            max=num;
            mx=line[i][0];
            my=line[i][1];
            }
           }

       }
       printf("%d %d %d",max,mx,my);
  return 0;
}


