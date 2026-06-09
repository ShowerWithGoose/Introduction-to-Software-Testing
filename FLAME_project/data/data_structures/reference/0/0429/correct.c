#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main()
{
    char a[100];
    const char s[2] = "-";
    char *token;
    int i,j,b[100]={0};
    gets(a);
    for(i=0,j=0;i<=strlen(a)-1;i++)
    {
        if(a[i]=='-')
        {
            b[j]=i;
            j++;
        }
    }
    token = strtok(a,s);
    j=0;
    while(token != NULL)
    {

        printf("%s",token);
        token = strtok(NULL,s);
        if(     (a[b[j]-1]<a[b[j]+1])   )
        {
            if( a[b[j]-1]>=48 && a[b[j]-1]<=57 && a[b[j]+1]>=48 && a[b[j]+1]<=57  )
            {
                for(i=a[b[j]-1]+1;i<=a[b[j]+1]-1;i++)
                printf("%c",i);
            }
            else if( a[b[j]-1]>=65 && a[b[j]-1]<=90 && a[b[j]+1]>=65 && a[b[j]+1]<=90  )
            {
                for(i=a[b[j]-1]+1;i<=a[b[j]+1]-1;i++)
                printf("%c",i);
            }
            else if( a[b[j]-1]>=97 && a[b[j]-1]<=122 && a[b[j]+1]>=97 && a[b[j]+1]<=122  )
            {
                for(i=a[b[j]-1]+1;i<=a[b[j]+1]-1;i++)
                printf("%c",i);
            }
            else
                if(token != NULL)
                    printf("-");
        }
        else
             if(token != NULL)
                printf("-");
        j++;
    }
    system("pause");
    return 0;
}

