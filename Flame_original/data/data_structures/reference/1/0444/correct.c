#include<stdio.h>
int a[21];
int b[21];
void digui(int n,int cnt)
{
    if(cnt==n)
    {
        for(int i=0;i<n;i++)
            {printf("%d",a[i]);
            printf(" ");}
            printf("\n");
    }
        for(int i=1;i<=n;i++)
        {
         if(b[i]==0)
         {
            a[cnt]=i;
            b[i]=1;
            digui(n,cnt+1);
            b[i]=0;
         }
        }

}
int main(){
    int n;
    scanf("%d",&n);
   digui(n,0);
  return 0;
}



