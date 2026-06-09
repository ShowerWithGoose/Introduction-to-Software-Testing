#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
int main()
{
    char a[1000];
    int i,j,k,l;
    char x,y,z;
    gets(a);
    l=strlen(a);
    for(i=0;i<l;i++)
    {
        if(a[i]=='-')
        {
            continue;
        }
        else if(a[i+1]!='-')
        {
            printf("%c",a[i]);
        }
        else
        {
            printf("%c",a[i]);
            if(a[i]>='a'&&a[i]<='z'&&a[i+2]>='a'&&a[i+2]<='z'&&a[i+2]+1>a[i])
            {
                x=a[i];
                y=a[i+2];
                for(z=x+1;z<y;z++)
                {
                    printf("%c",z);
                }
            }
            else if(a[i]>='A'&&a[i]<='Z'&&a[i+2]>='A'&&a[i+2]<='Z'&&a[i+2]+1>a[i])
            {
                x=a[i];
                y=a[i+2];
                for(z=x+1;z<y;z++)
                {
                    printf("%c",z);
                }
            }
            else if(a[i]>='0'&&a[i]<='9'&&a[i+2]>='0'&&a[i+2]<='9'&&a[i+2]+1>a[i])
            {
                x=a[i];
                y=a[i+2];
                for(z=x+1;z<y;z++)
                {
                    printf("%c",z);
                }
            }
            else
            {
                printf("-");
            }
        }
    }
    return 0;
}

