#include<stdio.h>
int n;
int ans[11],hash[11];
void search(int num)
{
   if(num>n)
   {
      for(int i=1;i<=n;i++)
      {
          printf("%d ",ans[i]);
      }
      printf("\n");
      return ;
   }
   for(int i=1;i<=n;i++)
   {
       if(!hash[i])
       {
           ans[num]=i;
           hash[i]=1;
           search(num+1);
           hash[i]=0;
       }
   }
}
int main()
{
    scanf("%d",&n);
    search(1);
    return 0;
}


