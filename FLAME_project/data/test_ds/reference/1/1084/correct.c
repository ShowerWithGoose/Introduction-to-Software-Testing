#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
#define ll long long
#define ull unsigned long long

int main()
{
    char c[10000],tem;
    int l,i;
    scanf("%s",c);
    l=strlen(c);
    printf("%c",c[0]);
    for ( i = 1; i < l-1; i++)
    {
        if(c[i]=='-'&&c[i+1]>c[i-1]&&((c[i-1]>='a'&&c[i+1]<='z')||(c[i-1]>='A'&&c[i+1]<='Z')||(c[i-1]>='0'&&c[i+1]<='9')))
        {
            for ( tem = c[i-1]+1; tem < c[i+1]; tem++)
            {
                printf("%c",tem);
            }
        }
        else printf("%c",c[i]);
    }
    printf("%c",c[l-1]);
    return 0;
}
