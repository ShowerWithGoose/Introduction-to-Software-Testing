#include<stdio.h>
#include<ctype.h>
#include<string.h>
int panduan(char b,char c)
{
    if(isdigit(b)==isdigit(c)&&islower(b)==islower(c)&&isupper(b)==isupper(c))
    return 1;
    else return 0;
}
int main()
{
    char a[10005],b,c;
    int i,j,k;
    scanf("%s",a);
    for(i=0;i<strlen(a);i++)
    {
        if(a[i]!='-')
        {
            printf("%c",a[i]);
        }
        else
        {
            b=a[i-1];
            c=a[i+1];
            j=panduan(b,c);
            if(j==1&&b<c)
            {
                for(k=b+1;k<c;k++)
                {
                    printf("%c",k);
                }
            }
            else printf("-");
        }
    }
}
