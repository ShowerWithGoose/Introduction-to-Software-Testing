#include<stdio.h>
#include<math.h>
#include<string.h>
#define eps 10e-10
#define GET_BIT(value, bit) (((value) >> bit) & 1)
int mark[10]={0}; // @@ Array size is 10, but indices go up to x (which can be 10), causing out-of-bounds access.
char ans[11]; // @@ Buffer size is too small to hold the space-separated permutation string, especially for N=10.
int x;



int main()
{
scanf("%d",&x);
dg(0,x); // @@ Function 'dg' is called before it is declared or defined, causing an implicit declaration compilation error.

return 0;
}
void dg(int m, int n)
{
int i;
if(n==0)
    {
    ans[m]='\0';
    printf("%s\n",ans);
    return;
    }    




for(int i=1;i<=x;i++) // @@ Variable 'i' is redeclared here, which may cause compilation errors in strict C standards.
if(mark[i]==0)
{
    mark[i]=1;
    ans[m]=i+'0'; // @@ Fails to handle two-digit number 10 correctly and omits required space separators between integers.
    dg(m+1,n-1); // @@ Index increment 'm+1' is incorrect as it doesn't account for space characters or two-digit numbers.
    mark[i]=0;


}




}