#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>
int main()
{
    char str[1000]={},copy[1000]={};
    int i,k=0,j=0;
    gets(str); // @@ [The function 'gets' is unsafe and has been removed from the C standard library since C11; using it may cause compilation errors with modern compilers that do not support it.]
    if(str[0]!='0')
    {
        for(i=0;i<strlen(str);i++)
        {
            if(str[i]!='.')
            k++;
            else
            break;
        }
        if(strlen(str)>1)
        {
        printf("%c",str[0]);
        printf(".");
        for(i=1;i<strlen(str);i++)
        {
            if(str[i]!='.')
            printf("%c",str[i]);
        }
        printf("e");
        printf("%d",k-1);
        }
        else
        {
            printf("%c",str[0]);
            printf("e0");
        }
        
    }
    else
    {
        for(i=0;i<strlen(str);i++)
        {
            if(str[i]=='0'||str[i]=='.')
            k++;
            else
            break;
        }
        for(i=0;i<strlen(str);i++)
        {
             if(str[i]!='0'&&str[i]!='.')
             {
             copy[j++]=str[i];
             }
        }
        if(strlen(copy)==1)
        {
        printf("%c",copy[0]);
        printf("e-%d",k-1);
        }
        else
        {
            printf("%c",copy[0]);
            printf(".");
            for(i=1;i<strlen(copy);i++)
            {
                printf("%c",copy[i]);
            }
            printf("e-%d",k-1);
        }

    }
}