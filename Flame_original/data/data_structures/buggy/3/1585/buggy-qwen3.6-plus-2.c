#include<stdio.h>
#include<string.h>
#include<math.h>
int main()
{
    char a[10000],b[10000],c[10000];
    scanf("%s",a);
    int h=strlen(a);
    if(h!=1)
    {
            if(a[0]=='0')
    {
        int u; // @@ Variable 'u' is declared but not initialized. If the loop fails to find a non-zero digit, using 'u' later causes undefined behavior and may trigger compilation warnings/errors in strict modes.
        int v=2;
        for(int i=2;i<h;i++) // @@ Declaring the loop variable 'i' inside the for statement is C99 syntax; compiling with older C89 standards will result in a compilation error.
        {
            if(a[i]!='0'){
                u=i;
                break;
            } 
        }
        c[0]=a[u];
        c[1]='.'; // @@ Unconditionally adds a decimal point. According to the output format, if the mantissa becomes an integer (e.g., input 0.5 should output 5e-1), the decimal point must be omitted.
        for(int i=u+1;i<h;i++)
        {
            c[v]=a[i];
            v++;
        }
        for(int i=0;i<v-1;i++)
        printf("%c",c[i]);
        printf("e");
        printf("-%d",u-1);
    }
    else{
        int m; // @@ Variable 'm' is declared but not initialized. If the input string lacks a decimal point, using 'm' causes undefined behavior.
        int n=2;
        b[0]=a[0];
        b[1]='.'; // @@ Unconditionally adds a decimal point, violating the output format requirement when the mantissa should be an integer.
        for(int i=1;i<h;i++)
        {
            if(a[i]=='.') m=i;
            else {
                b[n]=a[i];
                n++;
            }
        }
        for(int i=0;i<n;i++)
        printf("%c",b[i]);
        printf("e");
        printf("%d",m-1);
    }
    }
    if(h==1)
    {
        printf("%c",a[0]);
        printf("e0");
    }
    return 0;
}