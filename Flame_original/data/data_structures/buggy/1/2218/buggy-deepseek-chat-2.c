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
dg(0,x); // @@ [Error: Function 'dg' is called before it is declared or defined. In C, functions must be declared or defined before use, otherwise it leads to implicit declaration, which may cause compilation errors or undefined behavior.]

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
    
    
    
    
for(int i=1;i<=x;i++) // @@ [Error: Variable 'i' is redeclared in the for loop after already being declared as 'int i;' at the start of the function. This causes a compilation error in C (C90 standard) or may be invalid in some compilers.]
if(mark[i]==0)
{
    mark[i]=1;
    ans[m]=i+'0';
    dg(m+1,n-1);
    mark[i]=0;
    
    
}
    
    
    
    
}