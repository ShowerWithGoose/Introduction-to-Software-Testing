#include<stdio.h>

 int j=0;
 int b[105];


int k,a;
int main()
{
 while(scanf("%d",&k)!=EOF)
 {
  if(k==1)
  {
   scanf("%d",&a);
   if(j>=100)
   {
    printf("error ");
   }
   else
   {
    b[j]=a;
    j++;
   }
  }

  else if(k==0)
  {
   if(j<1)
   {
    printf("error ");
   }
   else
   {
    printf("%d ",b[j-1]);
    j--;
   }
  }

  else if(k==-1)
  {
   break;
  }
 }

 return 0;
}

