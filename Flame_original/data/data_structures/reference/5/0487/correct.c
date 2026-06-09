#include<stdio.h>

void bubblesort(int x[],int y[],int n);
int main()
{
 int a,b,i=0,j=0,d=0,i1,j1,flag=0,flag2;
 char c;
 int m[100],n[100],q[100],p[100],f[10000],g[10000];
 for(; ;){
 scanf("%d%d%c",&a,&b,&c);
 if(c!='\n'){
  m[i]=a;
  n[i]=b;
  i++;
 }
 else
 {
  m[i]=a;
  n[i]=b;
  i++;
  flag=1;
  break;
 } 
 }
 j=0;
 while(scanf("%d%d",&a,&b)!=EOF)
 {
  q[j]=a;
  p[j]=b;
  j++;
 }
 
d=0;
for(i1=0;i1<i;i1++)
{
 for(j1=0;j1<j;j1++)
 { 
  f[d]=m[i1]*q[j1];
  g[d]=n[i1]+p[j1];
  d++;
 }
}
bubblesort(f,g,d-1);
 
for(i=0;i<d;i++)
{if(f[i]!=0)
 printf("%d %d ",f[i],g[i]);
}
 return 0;
}
void bubblesort(int a[],int b[],int n)
{
int i,j,hold,flag;
for(i=0;i<n-1;i++)
{flag=0;
for(j=0;j<n-1-i;j++)
if(b[j]<b[j+1])
{hold =a[j];
a[j]=a[j+1];
a[j+1]=hold;
hold=b[j];
b[j]=b[j+1];
b[j+1]=hold;
flag=1;}
else if(b[j]==b[j+1])
{
 a[j]+=a[j+1];
 a[j+1]=0;
 flag=1;
}
if(0==flag)
break;}
}

