#include <stdio.h>
#include <stdlib.h>
struct line
{
 int n;
 int in1,in2;
 int out1,out2;
};
struct line l[100];
int main()
{
 int a,x1,y1,x2,y2,mark,cnt=0,max=0,k=-1;
 int i,j;
 
 for( i=0;i<100;i++)
 {
  l[i].n=1;
  l[i].in1=-114514;
  l[i].in2=-114514;
  l[i].out1=-114514;
  l[i].out2=-114514;
 }
 //
 scanf("%d",&a);
 for( i=0;i<a;i++)
 {
  mark=0;
  scanf("%d %d %d %d ",&x1,&y1,&x2,&y2);
  for( j=0;j<=cnt-1;j++)
  {
   if(l[j].in1==x1&&l[j].in2==y1&&mark==0)
   { 
    l[j].in1=x2;
    l[j].in2=y2;
    l[j].n++;
    mark=1;
   }
   if(l[j].out1==x1&&l[j].out2==y1&&mark==0)
   {
    l[j].out1=x2;
    l[j].out2=y2;
    l[j].n++;
    mark=1;
   }
   if(l[j].in1==x2&&l[j].in2==y2&&mark==0)
   {
 l[j].in1=x1;
 l[j].in2=y1;
 l[j].n++;
 mark=1;
}
if(l[j].out1==x2&&l[j].out2==y2&&mark==0)
{
 l[j].out1=x1;
 l[j].out2=y1;
 l[j].n++;
 mark=1;
}
 }
 if(mark==0)
 {
l[cnt].in1=x1;
l[cnt].in2=y1;
l[cnt].out1=x2;
l[cnt].out2=y2;
cnt++;
 }
 }
 //
for( i=0;i<=cnt-1;i++)
 {
 if(l[i].n>max)
 {
max=l[i].n;
k=i;
 }
 }
 mark=1;
 while(mark==1)
 {
 mark=0;
 for( j=0;j<=cnt-1;j++)
 {
 if(j==k)
 continue;
 if(l[j].in1==l[k].in1&&l[j].in2==l[k].in2)
 {
l[k].in1=l[j].out1;
l[k].in2=l[j].out2;
l[k].n+=l[j].n;
l[j].n=0;
l[j].in1=-1;
l[j].in2=-1;
l[j].out1=-1;
l[j].out2=-1;
mark=1;
 }
 if(l[j].out1==l[k].in1&&l[j].out2==l[k].in2)
 {
l[k].in1=l[j].in1;
l[k].in2=l[j].in2;
l[k].n+=l[j].n;
l[j].n=0;
l[j].in1=-1;
l[j].in2=-1;
l[j].out1=-1;
l[j].out2=-1;
mark=1;
 }
 if(l[j].in1==l[k].out1&&l[j].in2==l[k].out2)
 {
l[k].out1=l[j].out1;
l[k].out2=l[j].out2;
l[k].n+=l[j].n;
l[j].n=0;
l[j].in1=-1;
l[j].in2=-1;
l[j].out1=-1;
l[j].out2=-1;
mark=1;
 }
 if(l[j].out1==l[k].out1&&l[j].out2==l[k].out2)
 {
l[k].out1=l[j].in1;
l[k].out2=l[j].in2;
l[k].n+=l[j].n;
l[j].n=0;
l[j].in1=-1;
l[j].in2=-1;
l[j].out1=-1;
l[j].out2=-1;
mark=1;
 }
 }
 }
 if(l[k].in1<l[k].out1)
 printf("%d %d %d\n",l[k].n,l[k].in1,l[k].in2);
 if(l[k].in1>=l[k].out1)
 printf("%d %d %d\n",l[k].n,l[k].out1,l[k].out2);
 return 0;
}

