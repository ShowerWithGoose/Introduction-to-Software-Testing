#include <stdio.h>
#include <string.h>
#include <math.h>
#include <ctype.h>
int main()
{char c[110];
int i,j,k,x;
gets(c);
x=strlen(c);
for(i=0;i<x;i++)
{
    if(c[i]!='-')
        printf("%c",c[i]);
    else if(c[i]=='-')
    {
        if(c[i+1]<c[i-1])
            printf("-");
        else if(c[i+1]>='a'&&c[i+1]<='z'&&c[i-1]>='a'&&c[i-1]<='z')
        {
            for(j=1;c[i+1]>c[i-1]+j;j++)
                printf("%c",c[i-1]+j);
        }
        else if(c[i+1]>='A'&&c[i+1]<='Z'&&c[i-1]>='A'&&c[i-1]<='Z')
        {
            for(j=1;c[i+1]>c[i-1]+j;j++)
                printf("%c",c[i-1]+j);
        }
        else if(c[i+1]>='0'&&c[i+1]<='9'&&c[i-1]>='0'&&c[i-1]<='9')
        {
            for(j=1;c[i+1]>c[i-1]+j;j++)
                printf("%c",c[i-1]+j);
        }
        else
            printf("-");
    }
}

return 0;
}

