#include<stdio.h>
int main()
{
    char a[50], b, c;
    gets(a);
    for(int i=0; a[i]!='\0'; i++)
    {
        if(a[i]=='-')
        {
            b=a[i-1];
            if(a[i-1]>='0'&&a[i+1]<='9')
                for(int j=1; j<=(a[i+1]-a[i-1]-1); j++)
                {
                    b=b+1;
                    printf("%c",b);
                }
            else  if(a[i-1]>='a'&&a[i+1]<='z'||a[i-1]>='A'&&a[i+1]<='Z')
                for(int j=1; j<=(a[i+1]-a[i-1]-1); j++)
                {
                    b=b+1;
                    printf("%c",b);
                }
            if(a[i-1]>='0'&&a[i+1]<='9'||a[i-1]>='a'&&a[i+1]<='z'||a[i-1]>='A'&&a[i+1]<='Z')
                continue;
        }
        printf("%c",a[i]);
    }
    return 0;
}


