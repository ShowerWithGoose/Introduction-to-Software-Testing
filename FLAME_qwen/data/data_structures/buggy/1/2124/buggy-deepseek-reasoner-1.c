#include<stdio.h>
#include<math.h>
void f(int a[],int b[],int n,int dep);
int main()
{
    int a[100]={0};
    int b[100]={0};
    int n;
    scanf("%d",&n);
    f(a,b,n,1); // @@ [Error: Function 'f' is not declared before its use in 'main'. In C99 and later, implicit function declarations are not allowed, causing a compilation error. A forward declaration should be placed before 'main' as done in the reference program.]
    return 0;
}
void f(int a[],int b[],int n,int dep)
{
    int i;
    if(dep==n+1)
    {
        for(i=1;i<=n;i++)
        printf("%d",a[i]); // @@ [Note: Missing spaces between numbers. The expected output format requires each integer to be separated by a space, e.g., "%d ". This is a logic error that will cause incorrect output, but it is not a compilation error.]
        printf("\n");
        return;
    }
    for(i=1;i<=n;i++)
    {
        if(b[i]==0)  
        {
            b[i]=1;
            a[dep]=i;
            f(a,b,n,dep+1);
            b[i]=0;
        }
    }
}