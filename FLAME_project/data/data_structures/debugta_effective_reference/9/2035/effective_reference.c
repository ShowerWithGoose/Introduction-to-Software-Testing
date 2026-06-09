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
}s[105];
struct xian
{
    int sum;
    int qidianx,qidiany;
}m[100];
int i,j,k,pos,n,max,xulie,x,minx,miny;
int main()
{  
   for(i=0;i<100;i++)
   {
       m[i].qidianx=2147483647;
       m[i].qidiany=2147483647;
       m[i].sum=0;
   }
   scanf("%d",&n);
   for(i=0;i<n;i++)
   {
       scanf("%d%d%d%d",&s[i].qidianx,&s[i].qidiany,&s[i].zhongdianx,&s[i].zhongdiany);
   }
   for(i=0;i<n;i++)
   {
       for(j=i+1;j<n;j++)
       {
           if(s[i].qidianx==s[j].zhongdianx&&s[i].qidiany==s[j].zhongdiany)
           {
              
               if(s[i].shu==0&&s[j].shu==0)
               {
                pos++;
                s[i].shu=pos;
                s[j].shu=pos;
               }
               else if(s[i].shu==0&&s[j].shu!=0)
               {
                 s[i].shu=s[j].shu;
               }
               else if(s[i].shu!=0&&s[j].shu==0)
               {
                   s[j].shu=s[i].shu;
               }
               else if(s[i].shu!=0&&s[j].shu!=0)
               {
                   for(k=0;k<n;k++)
                   {
                       if(s[k].shu==s[i].shu)
                       s[k].shu=s[j].shu;
                   }
               }
           }
           else if(s[i].zhongdianx==s[j].qidianx&&s[i].zhongdiany==s[j].qidiany)
           {
               
               if(s[i].shu==0&&s[j].shu==0)
               {
                pos++;
                s[i].shu=pos;
                s[j].shu=pos;
                
               }
               else if(s[i].shu==0&&s[j].shu!=0)
               {
                 s[i].shu=s[j].shu;
               }
               else if(s[i].shu!=0&&s[j].shu==0)
               {
                s[j].shu=s[i].shu;
               }
               else if(s[i].shu!=0&&s[j].shu!=0)
               {
                   for(k=0;k<n;k++)
                   {
                       if(s[k].shu==s[i].shu)
                       s[k].shu=s[j].shu;
                   }
               }
           }
       }
   }
   pos++;
   for(i=0;i<n;i++)
   {
       if(s[i].shu==0)
       {
           s[i].shu=pos;
           pos++;
       }
   }
   
   for(i=0;i<n;i++)
   {
       if(s[i].shu>0)
       {
           x=s[i].shu;
           m[x].sum++;
       }
   }

   
      max=m[0].sum;
     
   
   for(i=0;i<n;i++)
   {
       if(m[i].sum>max)
       {
           max=m[i].sum;
           xulie=i;
       }
   }
   
   for(i=0;i<n;i++)
   {
       if(s[i].shu==xulie)
       {
           if(s[i].qidianx<m[xulie].qidianx)
           {
               m[xulie].qidianx=s[i].qidianx;
               m[xulie].qidiany=s[i].qidiany;
           }
       }
   }
   
   
   printf("%d %d %d\n",m[xulie].sum,m[xulie].qidianx,m[xulie].qidiany);
   system("pause");
   return 0;
}

