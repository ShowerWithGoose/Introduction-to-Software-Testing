#include<stdio.h>
#include<math.h>
#include<string.h>
#include<stdlib.h>
int b[10],a[10],n;
void dfs(int m)
{ 
  int i=0;
  if(m==n+1)
  {
   for(i=1;i<=n;i++)
   printf("%d ",b[i]);
   printf("\n");
   return;
  }
  for(i=1;i<=n;i++)
  {
   if(a[i]==0)
   {
       b[m]=i;
       a[i]=1;
       dfs(m+1);
       a[i]=0;
   }
  }
}
int read();
int main()
{

scanf("%d",&n);
dfs(1);   
}

