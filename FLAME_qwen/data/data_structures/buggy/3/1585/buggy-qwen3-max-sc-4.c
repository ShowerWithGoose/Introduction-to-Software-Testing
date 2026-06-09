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
        int u; // @@ [u may be used uninitialized if all digits after '0.' are zero, but problem states no trailing zeros and at least one non-zero digit exists, so logically safe; however, compiler may warn or error in strict mode]
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
        for(int i=0;i<v-1;i++)
        printf("%c",c[i]);
        printf("e");
        printf("-%d",u-1); // @@ [If input is "0.0", u remains uninitialized — but per problem description, there are no trailing zeros and all digits are significant, so this case shouldn't occur. However, the code assumes a non-zero digit exists after '0.', which is guaranteed by problem constraints. So this may not be the cause of compilation error.]
    }
    else{
        int m; // @@ [m may be used uninitialized if the input has no decimal point, but problem states input has digits before and after decimal point, so '.' must exist. Still, compiler might flag potential uninitialized use.]
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
        printf("%d",m-1); // @@ [If the loop never finds '.', m is uninitialized — but problem guarantees decimal point exists, so logically safe. However, some compilers may issue warning/error under strict settings.]
    }
    }
    if(h==1)
    {
        printf("%c",a[0]);
        printf("e0");
    }
    return 0;
}