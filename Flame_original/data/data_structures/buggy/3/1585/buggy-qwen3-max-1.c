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
        int u; // @@ [u may be used uninitialized if the loop doesn't find a non-zero digit, leading to undefined behavior]
        int v=2;
        for(int i=2;i<h;i++)
        {
            if(a[i]!='0'){
                u=i;
                break;
            } 
        }
        c[0]=a[u]; // @@ [if all digits after '0.' are zero, u remains uninitialized, causing undefined behavior]
        c[1]='.';
        for(int i=u+1;i<h;i++)
        {
            c[v]=a[i];
            v++;
        }
        for(int i=0;i<v-1;i++)
        printf("%c",c[i]);
        printf("e");
        printf("-%d",u-1); // @@ [u may be uninitialized here if input is like "0.0" or "0.00", which violates problem assumptions but still causes crash]
    }
    else{
        int m; // @@ [m may be used uninitialized if there's no '.' in the input string, leading to undefined behavior]
        int n=2;
        b[0]=a[0];
        b[1]='.';
        for(int i=1;i<h;i++)
        {
            if(a[i]=='.') m=i; // @@ [if input has no decimal point (e.g., "123"), m remains uninitialized]
            else {
                b[n]=a[i];
                n++;
            }
        }
        for(int i=0;i<n;i++)
        printf("%c",b[i]);
        printf("e");
        printf("%d",m-1); // @@ [m may be uninitialized here if input lacks a decimal point]
    }
    }
    if(h==1)
    {
        printf("%c",a[0]);
        printf("e0");
    }
    return 0;
}