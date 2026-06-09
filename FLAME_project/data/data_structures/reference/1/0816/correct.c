#include <stdio.h>

int a[9],flag[10]={0};

void dfs(int pos,int n)

{
     int i;
     if (pos==n)

     {

         for (i=0;i<n;i++)

            printf("%d ",a[i]);

         printf("\n");

     }

     else

     {

         for( i=1;i<=n;i++)

         {

            if(flag[i])

                continue;

            a[pos]=i;

            flag[i]=1;

            dfs(pos+1,n);  

            flag[i]=0;

         }

     }

}

int main()

{

    int n;

    scanf("%d",&n);

    dfs(0,n);

    return 0;

}


