#include<stdio.h>
int a[100];int fangru[100];int n;
void dfs(int s)
{
 int i;
 if(s==n+1)
 {
  for(i=1;i<=n;i++)
  {
   printf("%d ",a[i]);
  }
   printf("\n");
   return;
  
 }
 for(i=1;i<=n;i++)
 {
  if(fangru[i]==0)
  {
   a[s]=i;
   fangru[i]=1;
   dfs(s+1);
   fangru[i]=0;
  }
  }
}
int main()
{
 scanf("%d",&n);
 dfs(1);
 return 0;
 
}

