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
dg(0,x); // @@ [Function 'dg' is called before it is declared or defined, leading to a compilation error in C (implicit function declaration is invalid in C99 and later).]

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
    
    
    
    
for(int i=1;i<=x;i++)    
if(mark[i]==0)
{
    mark[i]=1;
    ans[m]=i+'0';
    dg(m+1,n-1);
    mark[i]=0;
    
    
}
    
    
    
    
}