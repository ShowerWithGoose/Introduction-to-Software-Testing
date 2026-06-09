#include <stdio.h>
#include <string.h>

int main()
{
    char s[102]="",a[105]="";
    int i=0,j=0,d=0;   //d=指数部分大小
    gets(s);
    if(s[1]=='.')   //
    {
        if(s[0]!='0')   //
            {
                strcpy(a,s);d=0;
            }
        else   //
        {

            for(i=2;s[i]=='0';i++);
            a[0]=s[i];d=1-i;
            if(i != strlen(s)-1)
            {
                a[1]='.';
                for(j=2,i++;s[i]!='\0';i++,j++)
                {
                    a[j]=s[i];
                }
                a[j]='\0';
            }
            else
            {
                a[1]='\0';
            }
        }
    }
    else
    {
        a[0]=s[0];a[1]='.';
        for(i=1,j=2;s[i]!='\0';i++,j++)
        {
            if(s[i]=='.'){i++;d=i-2;}
            a[j]=s[i];
        }
        a[j]='\0';
    }

    printf("%se%d",a,d);
    return 0;
}



