#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
    int n1,n2;
    int xss[105],css[105];
struct node1
{
    int xs;
    int cs;
}mk1[1005];
struct node2
{
    int xs;
    int cs;
}mk2[1005];
int read1()
{
int i=0;
char ch;
while(scanf("%d",&mk1[i].xs)!=EOF)
{
    scanf("%d%c",&mk1[i].cs,&ch);
    i++;
    if(ch=='\n')
        break;
}
return i;
}
int read2()
{
int i=0;
char ch;
while(scanf("%d",&mk2[i].xs)!=EOF)
{
    scanf("%d%c",&mk2[i].cs,&ch);
    i++;
    if(ch=='\n')
        break;
}
return i;
}
struct NODE
{
    int a[1005];
    int b[1005];
}gg[1005];

void sort(int e)
{
    int ccss,xxss;
    for(int w=0;w<e;w++)
    {
        for(int q=w+1;q<e;q++)
        {
            if(css[w]<css[q])
            {
             ccss=css[w];
             css[w]=css[q];
             css[q]=ccss;
             xxss=xss[w];
             xss[w]=xss[q];
             xss[q]=xxss;
            }
        }
    }
}
int main()
{
int e=0;
   n1=read1();
   n2=read2();
   for(int i=0;i<n1;i++)
   {
       for(int j=0;j<n2;j++)
       {
           gg[i].a[j]=mk1[i].xs*mk2[j].xs;
           gg[i].b[j]=mk1[i].cs+mk2[j].cs;
       }
   }
   for(int i=0;i<n1;i++)
   {
       for(int k=0;k<n2;k++)
       {
           for(int f=i+1;f<n1;f++)
           {
               for(int u=0;u<n2;u++)
               {
                   if(gg[i].b[k]==gg[f].b[u]&&gg[i].a[k]!=0)
                   {
                       gg[i].a[k]+=gg[f].a[u];
                       gg[f].a[u]=0;
                   }
               }
           }
       }
   }
   for(int y=0;y<n1;y++)
   {
       for(int r=0;r<n2;r++)
       {
           if(gg[y].a[r]!=0)
           {
               xss[e]=gg[y].a[r];
               css[e]=gg[y].b[r];
               e++;
           }
   }
   }
   sort(e);
   for(int t=0;t<e;t++)
   {
       printf("%d %d ",xss[t],css[t]);
   }
  return 0;
}

