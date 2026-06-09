#include<stdio.h>
#include<string.h>
#include<math.h>
#include<ctype.h>
char a[100];
#define ArrayNum(x) (sizeof(x)/sizeof(x[0]))
int main()
{

    int i,k;
    char j;
    gets(a);

    for(i=0;i<strlen(a)-1;i++)
    {

        if(a[i+1]!='-'&&a[i]!='-')
            printf("%c",a[i]);
        else if(a[i+1]=='-')
        {
            if(a[i]<='9'&&a[i]>='0'&&a[i+2]<='9'&&a[i+2]>='0'&&a[i+2]>a[i])
            {
                for(j=a[i];j<a[i+2];j++)
                    printf("%c",j);
            }
            else if(a[i]<='z'&&a[i]>='a'&&a[i+2]<='z'&&a[i+2]>='a'&&a[i+2]>a[i])
            {
                for(j=a[i];j<a[i+2];j++)
                    printf("%c",j);
            }
            else if(a[i]<='Z'&&a[i]>='A'&&a[i+2]<='Z'&&a[i+2]>='A'&&a[i+2]>a[i])
            {
                for(j=a[i];j<a[i+2];j++)
                    printf("%c",j);
            }
            else
               printf("%c%c",a[i],'-');

        }

    }
     printf("%c",a[i]);
    return 0;
}



