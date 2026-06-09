#include<stdio.h>
#include<string.h>
int main(void)
{
    char a[100];
    gets(a);
    for(int i=0;i<strlen(a);i++)
    {
        if(a[i]=='-')
        {
            if((a[i-1]>='a') && (a[i-1]<='z') && (a[i+1]>='a') && (a[i+1]<='z') && (a[i-1]<a[i+1]))
            {
                for(int j=1;j<(a[i+1]-a[i-1]);j++)
                {
                    char c=a[i-1]+j;
                    printf("%c",c);
                }
            }
            else if((a[i-1]>='A') && (a[i-1]<='Z') && (a[i+1]>='A') && (a[i+1]<='Z') && (a[i-1]<a[i+1]))
                for(int j=1;j<(a[i+1]-a[i-1]);j++)
                {
                    char c=a[i-1]+j;
                    printf("%c",c);
                }
            else if((a[i-1]>='0') && (a[i-1]<='9') && (a[i+1]>='0') && (a[i+1]<='9') && (a[i-1]<a[i+1]))
                for(int j=1;j<(a[i+1]-a[i-1]);j++)
                {
                    char c=a[i-1]+j;
                    printf("%c",c);
                }
            else
            {
                printf("-");
            }
        }
        else
        {
            printf("%c",a[i]);
        }
    }
    return 0;
}


