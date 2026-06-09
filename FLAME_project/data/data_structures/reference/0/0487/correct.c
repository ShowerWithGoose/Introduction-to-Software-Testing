#include <stdio.h>
#include<math.h>
#include<string.h>
#include<ctype.h>
#define arraynum(x)  (sizeof(x)/sizeof(x[o])
#define eps (1*10^-9)
int main()
{
    char a[1000];
    int i,j,len;
    scanf("%s",a);
    len=strlen(a);

    for(i=0;i<len;i++)
    {
        if(a[i]!='-')
        {
            printf("%c",a[i]);
        }
        else if(i==0||a[i+1]=='\0')
            printf("%c",a[i]);
        else if((a[i-1]>='a'&&a[i-1]<='z')&&(a[i+1]>='a'&&a[i+1]<='z')&&a[i-1]<a[i+1])
        {
            for(j=1;j<=a[i+1]-a[i-1]-1;j++)
            {
                printf("%c",a[i-1]+j);
            }
        }
        else if(a[i-1]>='A'&&a[i-1]<='Z'&&a[i+1]>='A'&&a[i+1]<='Z'&&a[i-1]<a[i+1])
        {
           for(j=1;j<=a[i+1]-a[i-1]-1;j++)
            {
                printf("%c",a[i-1]+j);
            }
        }
        else if(a[i-1]<='9'&&a[i-1]>='0'&&a[i+1]<='9'&&a[i+1]>='0'&&a[i-1]<a[i+1])
        {
            for(j=1;j<=a[i+1]-a[i-1]-1;j++)
            {
                printf("%c",a[i-1]+j);
            }
        }
        else
            printf("%c",a[i]);
    }
    return 0;
}



