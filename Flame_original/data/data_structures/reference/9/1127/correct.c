#include<stdio.h> 
#include<stdlib.h>
#include<string.h>
#include<math.h>
struct duan
{
    int qidianx,qidiany;
    int zhongdianx,zhongdiany;
    int qi,zhong;
    int shu;
}xd[105];
struct xian
{
    int sum;
    int qidianx,qidiany;
}lx[100];
int i,j,k,m,n,max,num,x,minx,miny;
int main()
{  
   for(i=0;i<100;i++)
   {
       lx[i].qidianx=2147483647;
       lx[i].qidiany=2147483647;
       lx[i].sum=0;
   }
   scanf("%d",&n);
   for(i=0;i<n;i++)
   {
       scanf("%d%d%d%d",&xd[i].qidianx,&xd[i].qidiany,&xd[i].zhongdianx,&xd[i].zhongdiany);
   }
   for(i=0;i<n;i++)
   {
       for(j=i+1;j<n;j++)
       {
           if(xd[i].qidianx==xd[j].zhongdianx&&xd[i].qidiany==xd[j].zhongdiany)
           {
              
               if(xd[i].shu==0&&xd[j].shu==0)
               {
                m++;
                xd[i].shu=m;
                xd[j].shu=m;
               }
               else if(xd[i].shu==0&&xd[j].shu!=0)
               {
                 xd[i].shu=xd[j].shu;
               }
               else if(xd[i].shu!=0&&xd[j].shu==0)
               {
                   xd[j].shu=xd[i].shu;
               }
               else if(xd[i].shu!=0&&xd[j].shu!=0)
               {
                   for(k=0;k<n;k++)
                   {
                       if(xd[k].shu==xd[i].shu)
                       xd[k].shu=xd[j].shu;
                   }
               }
           }
           else if(xd[i].zhongdianx==xd[j].qidianx&&xd[i].zhongdiany==xd[j].qidiany)
           {
               
               if(xd[i].shu==0&&xd[j].shu==0)
               {
                m++;
                xd[i].shu=m;
                xd[j].shu=m;
                
               }
               else if(xd[i].shu==0&&xd[j].shu!=0)
               {
                 xd[i].shu=xd[j].shu;
               }
               else if(xd[i].shu!=0&&xd[j].shu==0)
               {
                xd[j].shu=xd[i].shu;
               }
               else if(xd[i].shu!=0&&xd[j].shu!=0)
               {
                   for(k=0;k<n;k++)
                   {
                       if(xd[k].shu==xd[i].shu)
                       xd[k].shu=xd[j].shu;
                   }
               }
           }
       }
   }
   m++;
   for(i=0;i<n;i++)
   {
       if(xd[i].shu==0)
       {
           xd[i].shu=m;
           m++;
       }
   }
   
   for(i=0;i<n;i++)
   {
       if(xd[i].shu>0)
       {
           x=xd[i].shu;
           lx[x].sum++;
       }
   }

   
      max=lx[0].sum;
     
   
   for(i=0;i<n;i++)
   {
       if(lx[i].sum>max)
       {
           max=lx[i].sum;
           num=i;
       }
   }
   
   for(i=0;i<n;i++)
   {
       if(xd[i].shu==num)
       {
           if(xd[i].qidianx<lx[num].qidianx)
           {
               lx[num].qidianx=xd[i].qidianx;
               lx[num].qidiany=xd[i].qidiany;
           }
       }
   }
   
   
   printf("%d %d %d\n",lx[num].sum,lx[num].qidianx,lx[num].qidiany);
   system("pause");
   return 0;
}

