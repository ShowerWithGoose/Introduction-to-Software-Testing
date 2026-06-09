#include <stdio.h>
int num[100]={0};
int n,a[100];
int main()
{
    scanf("%d",&n);
    dfs(0);
    return 0;
}


int dfs(int h)
{  int i;
   if(h==n)
   {
       for(i=0;i<n;i++)
       {
           printf("%d ",a[i]);
       }

   printf("\n");
   return;}
   {for(i=0;i<n;i++)
     {
         if(num[i]==0)
         {a[h]=i+1;
          num[i]=1;
            dfs(h+1);
             num[i]=0;
         }
     }

   }
}

