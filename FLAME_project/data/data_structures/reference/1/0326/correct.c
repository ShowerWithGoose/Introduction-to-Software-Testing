#include <stdio.h>
int a[11]={0},book[11]={0},cnt=0;
void fun(int b,int z)
{int i;
 if(z==b)
 {
 for( i=1;i<=b;i++)
 {
 if(book[i]==0)
 {
 a[z]=i;
 }
 }
 for( i=1;i<b;i++)
 printf("%d ",a[i]);
 printf("%d\n",a[b]);
}
else
{
 for( i=1;i<=b;i++)
 {
 if(book[i]==0)
 {
 a[z]=i;
book[i]=1;
 fun(b,z+1);
 book[i]=0;
 }
 }
 }
}
int main()
{
int n;
 scanf("%d",&n);
fun(n,1);
 return 0;
}

