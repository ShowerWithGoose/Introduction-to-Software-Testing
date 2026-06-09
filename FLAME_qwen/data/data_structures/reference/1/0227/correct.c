#include<stdio.h>
#include<math.h>
#include<string.h>
#include<stdlib.h>
int a[10],b[10],n;
void dfs(int m)
{ 
  int i=0;
  if(m==n+1)
  {
   for(i=1;i<=n;i++)
   printf("%d ",a[i]);
   printf("\n");
   return;
  }
  for(i=1;i<=n;i++)
  {
   if(b[i]==0)
   {
       a[m]=i;
       b[i]=1;
       dfs(m+1);
       b[i]=0;
   }
  }
}
int read();
int main()
{

scanf("%d",&n);
dfs(1);   
}

