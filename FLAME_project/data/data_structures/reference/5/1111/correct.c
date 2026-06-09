#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int a[1024][3],b[1024][3],c[1024][3];
int m,n,t;
void sort(int s[][3],int n);
void multiply(int m,int n);
int main()
{
 int i;
 char d;
 d=' ';
 while(d!='\n')
{scanf("%d%d%c",&a[m][0],&a[m][1],&d);m++;}
d=' ';
 while(d!='\n')
{scanf("%d%d%c",&b[n][0],&b[n][1],&d);n++;}
 t=n*m-1;
multiply(m,n);
sort(c,t);
for(i=0;i<=t+1;i++)
{
 if(c[i][2])printf("%d %d ",c[i][0],c[i][1]);
}
 return 0;
}
void sort(int s[][3],int n)
{
 int i,j,k,tmp;
  for(i=0;i<n;i++)
  {
    for(j=i;j<=n;j++)
    {
     if((s[j][1]>s[i][1])&&s[j][2])
     {
      for(k=0;k<3;k++)
      {tmp=s[j][k];s[j][k]=s[i][k];s[i][k]=tmp;}
     }
    }
  }
   for(i=0;i<n;i++)
  {
    for(j=i;j<=n;j++)
    {
     if((s[j][1]==s[i][1])&&(i!=j)){s[i][0]=s[i][0]+s[j][0];s[j][2]=0;}
    }
  }
}
void multiply(int m,int n)
{
  int i=1,j=1,k=0 ;
for(i=0;i<m;i++)
  {
    for(j=0;j<n;j++)
    {
     c[k][0]=a[i][0]*b[j][0];
     c[k][1]=a[i][1]+b[j][1];
     c[k][2]=1;
     k++;
    }
  }
}

