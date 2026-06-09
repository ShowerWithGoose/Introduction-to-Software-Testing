#include <stdio.h>
#include <math.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#define ArrayNum(x) (sizeof(x)/sizeof(x[0]))
#define MAX(a,b) (((a)>(b))?(a):(b))
#define MIN(a,b) (((a)<(b))?(a):(b))
#define ll long long
#define ull unsigned long long

int a[11],book[11],n;
void dfs(int step)
{
    int i;
    if(n+1==step)
    {
        for(i=1;i<=n;i++)
        {
            printf("%d ",a[i]);
        }
        printf("\n");
         return;
    }
   
   for(int i=1;i<=n;i++)
   {
       if(book[i]==0)
       {
           a[step]=i;
           book[i]=1;
      
       dfs(step+1);
       book[i]=0; }
   }
   return;


}
int main(){
  scanf("%d",&n);
  dfs(1);
  return 0;

}
