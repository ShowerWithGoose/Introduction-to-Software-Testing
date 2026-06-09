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
dg(0,x); // @@ [function 'dg' is called before it is declared or defined, causing a compilation error in C (implicit function declaration is invalid in C99 and later)]

return 0;
}
void dg(int m, int n) // @@ [function 'dg' is defined after being used in main; in C, functions must be declared before use unless previously defined]
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