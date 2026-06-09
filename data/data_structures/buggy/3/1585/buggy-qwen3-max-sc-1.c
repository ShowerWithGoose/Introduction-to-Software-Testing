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
        int u; // @@ [u may be used uninitialized if all digits after '0.' are zero, but problem states all digits are significant so this might not occur; however, logic assumes a non-zero digit exists]
        int v=2;
        for(int i=2;i<h;i++)
        {
            if(a[i]!='0'){
                u=i;
                break;
            } 
        }
        c[0]=a[u]; // @@ [if input is "0.0", u is uninitialized -> undefined behavior; but per problem, no trailing zeros and all digits significant, so "0.0" won't appear. However, if input is "0." (invalid per problem), also fails. Still, loop may not set u if no non-zero found, leading to UB]
        c[1]='.';
        for(int i=u+1;i<h;i++)
        {
            c[v]=a[i];
            v++;
        }
        for(int i=0;i<v-1;i++) // @@ [if there are no digits after the first non-zero digit, v remains 2, so loop runs from 0 to 0 (i < 1), printing only c[0]; but should print just the digit without decimal point in that case per spec]
        printf("%c",c[i]);
        printf("e");
        printf("-%d",u-1);
    }
    else{
        int m; // @@ [m may be uninitialized if there's no '.' in the input, but problem states input has digits before and after decimal point, so '.' must exist. However, code doesn't validate that, and if '.' is missing, m is used uninitialized]
        int n=2;
        b[0]=a[0];
        b[1]='.';
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
        printf("%d",m-1); // @@ [if input has no decimal point, m is uninitialized → undefined behavior. Though problem guarantees decimal point exists, robustness issue remains]
    }
    }
    if(h==1)
    {
        printf("%c",a[0]);
        printf("e0");
    }
    return 0;
}