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
        int u; // @@ [u may be used uninitialized if all digits after '0.' are zero, but problem states all digits are significant so this might not occur; however, logic assumes there is a non-zero digit]
        int v=2;
        for(int i=2;i<h;i++)
        {
            if(a[i]!='0'){
                u=i;
                break;
            } 
        }
        c[0]=a[u]; // @@ [if input is "0.0", u is uninitialized -> undefined behavior; but per problem, no trailing zeros and all digits significant, so "0.0" won't appear. However, what if input is "0.1"? Then i starts at 2 (after '0','.'), which is correct. But if input has only one digit after decimal like "0.5", h=3, loop runs i=2, finds '5', ok. So maybe not error here. But note: the code assumes decimal point is at index 1 always when a[0]=='0'. This is wrong if input is like "00.123" — but problem says first digit before decimal can be 0 only if it's alone, so valid input with leading zero must be "0.xxx". So decimal is at index 1. So that assumption holds. However, the real bug is below:]
        c[1]='.';
        for(int i=u+1;i<h;i++)
        {
            c[v]=a[i];
            v++;
        }
        for(int i=0;i<v-1;i++) // @@ [should be i < v, because c[v-1] is last assigned char; current loop stops before printing last digit]
        printf("%c",c[i]);
        printf("e");
        printf("-%d",u-1); // @@ [exponent should be -(u - 1) because position of first non-zero after decimal at index u (0-based in whole string). For "0.00123", u=3 (char '1'), exponent = -2, and u-1 = 2, so "-2" is correct. So this seems right.]
    }
    else{
        int m; // @@ [m may be uninitialized if there's no '.' in the input, but problem states input has digits before and after decimal point, so '.' must exist. So safe?]
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
        printf("%d",m-1); // @@ [correct: for "123.45", m=3, exponent=2, m-1=2 → correct]
    }
    }
    if(h==1)
    {
        printf("%c",a[0]);
        printf("e0");
    }
    return 0;
}