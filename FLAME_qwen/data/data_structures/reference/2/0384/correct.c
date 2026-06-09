#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#define MAX 100000
char c[MAX];
int n,b[MAX],d,e,a[MAX],cnt,f[MAX],t,tim,r[MAX],i;
int main()
{
 gets(c);
 n=strlen(c);
 for( i=0;i<n;i++)
 {
  if(c[i]==' ')
  {
   continue;
  }
  else if(c[i]>='0'&&c[i]<='9')
  {
   d=d*10+c[i]-'0';
  }
  else
  {
   f[++t]=d;
   d=0;
   if(c[i]=='+')
   {
    b[++e]=1;
   }
   else if(c[i]=='-')
   {
    b[++e]=2;
   }
   else if(c[i]=='*')
   {
    b[++e]=3;
   }
   else if(c[i]!='=')
   {
    b[++e]=4;
   }
  }
 }
 t=1;
 for(i=1;i<=e;i++)
 {
  if(b[i]==1||b[i]==2)
  {
   a[++cnt]=f[t++];
   r[++tim]=b[i];
  }
  else
  {
   n=f[t++];
   d=f[t];
   if(b[i]==3)
   {
    f[t]=n*d;
   }
   else
   {
    f[t]=n/d;
   }
  }
 }
 if(f[t])
 {
  a[++cnt]=f[t];
 }
 t=1;
 for(i=1;i<=tim;i++)
 {
  n=a[t++];
  d=a[t];
  if(r[i]==1)
  {
   a[t]=n+d;
  }
  else
  {
   a[t]=n-d;
  }
 }
 printf("%d",a[t]);
 return 0;
}

