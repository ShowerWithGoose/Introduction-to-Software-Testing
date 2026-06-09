#include<stdio.h>
#include<string.h>
void expand(char a[])
{
    int l=strlen(a);
    for(int i=0;i<l;i++)
    {
        if(a[i]=='-')
        {
            if((a[i-1]>='0'&&a[i-1]<='9')&&(a[i+1]>='0'&&a[i+1]<='9')&&(a[i+1]>a[i-1]))
            {
                for(int j=1;j<(a[i+1]-a[i-1]);j++)
                printf("%c",a[i-1]+j);
            }
            else if((a[i-1]>='a'&&a[i-1]<='z')&&(a[i+1]>='a'&&a[i+1]<='z')&&(a[i+1]>a[i-1]))
            {
                for(int j=1;j<(a[i+1]-a[i-1]);j++)
                printf("%c",a[i-1]+j);
            }
            else if((a[i-1]>='A'&&a[i-1]<='Z')&&(a[i+1]>='A'&&a[i+1]<='Z')&&(a[i+1]>a[i-1]))
            {
                for(int j=1;j<(a[i+1]-a[i-1]);j++)
                printf("%c",a[i-1]+j);
            }
            else
            printf("%c",a[i]);
        }
        else
        printf("%c",a[i]);
    }
}
int main()
{
    char s[100000];
    gets(s);
    expand(s);
    return 0;
}

