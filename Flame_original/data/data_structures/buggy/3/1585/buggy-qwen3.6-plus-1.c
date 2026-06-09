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
        int u; // @@ Variable 'u' is used without initialization, which can lead to undefined behavior or compilation errors with strict flags.
        int v=2;
        for(int i=2;i<h;i++)
        {
            if(a[i]!='0'){
                u=i;
                break;
            } 
        }
        c[0]=a[u];
        c[1]='.';
        for(int i=u+1;i<h;i++)
        {
            c[v]=a[i];
            v++;
        }
        for(int i=0;i<v-1;i++) // @@ The loop condition i<v-1 incorrectly omits the last digit of the mantissa. It should be i<v to correctly print all stored characters.
        printf("%c",c[i]);
        printf("e");
        printf("-%d",u-1);
    }
    else{
        int m; // @@ Variable 'm' is used without initialization, which can lead to undefined behavior or compilation errors with strict flags.
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