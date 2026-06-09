#include<stdio.h>
#include<math.h>
#include<string.h>
#define eps 10e-10
#define GET_BIT(value, bit) (((value) >> bit) & 1)
int mark[10]={0};
char ans[11];
int x;



int main()
{
scanf("%d",&x);
dg(0,x); // @@ [Function dg is called before its declaration; this may cause compilation issues in strict C standards, but more critically, the logic uses char array to store digits without spaces, violating output format]

return 0;
}
void dg(int m, int n)
{
int i;
if(n==0)
    {
    ans[m]='\0';
    printf("%s\n",ans); // @@ [This prints digits concatenated (e.g., "12") instead of space-separated ("1 2"), which violates the required output format]
    return;
    }    
    
    
    
    
for(int i=1;i<=x;i++)    
if(mark[i]==0)
{
    mark[i]=1;
    ans[m]=i+'0'; // @@ [Storing digit characters without spaces; should store integers or format with spaces during output]
    dg(m+1,n-1);
    mark[i]=0;
    
    
}
    
    
    
    
}