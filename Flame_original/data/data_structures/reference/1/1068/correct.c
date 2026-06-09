#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
#include <stdio.h>
void DLF(int a[],int b[],int n,int depth)
{
  int i;
  if(depth==n+1)
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
    if(b[i]==0)
    {
      b[i]=1;
      a[depth]=i;
      DLF(a,b,n,depth+1);
      b[i]=0;
    }
  }
}
int main()
{
    int n;
    scanf("%d",&n);
    int a[11]={0};
    int b[11]={0};
    DLF(a,b,n,1);
    return 0;
}

