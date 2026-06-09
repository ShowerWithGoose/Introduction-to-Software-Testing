#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char s[100]="";
    int i=0,I=0,k=0,j=0,n=0;
    gets(s);
    n=strlen(s);
    I=0;
    for(i=0;i<=n-2;i++)
    {
        if(s[i]=='-')
        {
            if(s[i+1]>s[i-1])
            {
                if((s[i-1]>='0'&&s[i+1]<='9')||(s[i-1]>='A'&&s[i+1]<='Z')||(s[i-1]>='a'&&s[i+1]<='z'))
                {
                    for(k=I;k<=i-1;k++)
                        printf("%c",s[k]);
                    k--;
                    for(j=1;j<=s[i+1]-s[i-1]-1;j++)
                        printf("%c",s[k]+j);
                    I=i+1;
                }
                else
                {
                    for(;I<=i-1;I++)
                        printf("%c",s[I]);
                    printf("-");
                    I=i+1;
                }
            }
            else
            {
                for(;I<=i-1;I++)
                    printf("%c",s[I]);
                printf("-");
                I=i+1;
            }
        }
    }
    if(s[i+1]=='\0')
    {
        for(j=I;j<=i;j++)
            printf("%c",s[j]);
    }
    return 0;
}



