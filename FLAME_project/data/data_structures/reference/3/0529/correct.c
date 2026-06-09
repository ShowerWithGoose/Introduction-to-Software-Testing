#include <stdio.h>
#include <string.h>
#include <math.h>
#include <ctype.h>
int main()
{char c[110];
int i,j,k,x,y;
gets(c);
x=strlen(c);
for(i=0;i<x;i++)
{
    if(c[i]=='.')
        j=i;
}
if(j==1)
    {
        if(c[0]=='0')
        {
            for(y=2;c[y]=='0';y++)
                continue;
            if(y+1==x)
                printf("%ce%d",c[y],1-y);
            else
{
            for(k=y;k<x;k++)
            {
                printf("%c",c[k]);
                if(k==y)
                    printf(".");
            }
            printf("e%d",1-y);}
        }

        else if(c[0]!='0')
    printf("%se0",c);
    }
else if(j>1)
    {for(k=0;k<x;k++)
    {if(k==j)
    k++;
        printf("%c",c[k]);
    if(k==0)
        printf(".");
    }
    printf("e%d",j-1);}
return 0;
}



