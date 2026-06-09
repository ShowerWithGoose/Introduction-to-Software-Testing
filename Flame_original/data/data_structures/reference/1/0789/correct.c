#include<stdio.h>
int a[11]={1,2,3,4,5,6,7,8,9,10,11};
int re[11];
int q[11];
void dfs(int t,int r)
{
 if(t>r)
 {
  for(int i=1;i<=r;i++)
   printf("%d ",re[i]);
  printf("\n");
  return ;
 } 
 for(int i=0;i<r;i++)
 {
  if(q[i]==0)
  {
   re[t]=a[i];
   q[i]=1;
   dfs(t+1,r);
   q[i]=0; 
  }
 }
 return ;
}
int main()
{
 int n;
 scanf("%d",&n);
 dfs(1,n);
 return 0;
}

