#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
#define ll long long
#define ull unsigned long long

int main()
{
    char c[107];
    int l,i,j,k,f;
    scanf("%s",c);
    l=strlen(c);
    for ( i = 0; i < l; i++)
    {
        if(c[i]=='.')
        {
            k=i;
            break;
        }
    }
    for ( i = 0; i < l; i++)
    {
        if(i==k)continue;
        if(c[i]!='0')
        {
            f=i;
            break;
        }
    }
    if(f==l-1)printf("%c",c[f]);
    else printf("%c.",c[f]);
    for ( i = f+1; i < l; i++)
    {
        if(i==k)continue;
        printf("%c",c[i]);
    }
    j=k-f;
    if(j>0)j--;
    printf("e%d",j);
    return 0;
}
