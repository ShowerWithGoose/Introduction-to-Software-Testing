#include <stdio.h>
#include <math.h>
#include <string.h>
char s[110] = {0};
int main()
{
    char a,b;
    int c=0;
    b= getchar();
    while (b!= EOF)
    {
        s[c++]=b;
        b= getchar();
    }
    for (int i = 0; i < strlen(s); i++)
    {
        if (s[i]=='-')
        {
            if (i==0)
            {
                printf("-");
            }

            else if (s[i-1]>='0'&&s[i-1]<'9')
            {
                if (s[i+1]>s[i-1]&&s[i+1]<='9')
                {
                    for (int j=1;j<(s[i+1]+'0')-(s[i-1]+'0');j++)
                    {
                        a=s[i-1]+j;
                        printf("%c",a);
                    }
                }
                else
                {
                    printf("-");
                }
            }

            else if (s[i-1]>='A'&&s[i-1]<'Z')
            {
                if (s[i+1]>s[i-1]&&s[i+1]<='Z')
                {
                    for (int j=1;j<(s[i+1]+'0')-(s[i-1]+'0');j++)
                    {
                        a=s[i-1]+j;
                        printf("%c",a);
                    }
                }
                else printf("-");
            }

            else if (s[i-1]>='a'&&s[i-1]<'z')
            {
                if (s[i+1]>s[i-1]&&s[i+1]<='z')
                {
                    for (int j=1;j<(s[i+1]+'0')-(s[i-1]+'0');j++)
                    {
                        a=s[i-1]+j;
                        printf("%c",a);
                    }
                }
                else printf("-");
            }

            else printf("-");
        }
        else printf("%c",s[i]);
    }

    return 0;
}

