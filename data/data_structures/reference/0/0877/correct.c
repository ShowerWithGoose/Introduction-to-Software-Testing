#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>

int main()
{
    char s[1000];
    int l,r;
    scanf("%s",&s);
    int len=strlen(s);
    printf("%c",s[0]);
    for(int i=1;i<len;i++)
    {
        if(s[i]=='-'&&s[i-1]<s[i+1])
        {
            if (('a'<=s[i-1]&&s[i+1]<='z')||('A'<=s[i-1]&&s[i+1]<='Z')||('0'<=s[i-1]&&s[i+1]<='9'))
            {
                l=s[i-1],r=s[i+1];
                for(int j=l+1;j<r;j++)
                {
                    printf("%c",j);
                }
            }
            else
            {
                printf("-");
            }
        }
        else
        {
            printf("%c",s[i]);
        }

    }
    system("pause");
    return 0;
}


