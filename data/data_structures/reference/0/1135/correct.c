#include<stdio.h>
#include<string.h>
#include<ctype.h>
char s[105];
int main()
{
    int i;
    gets(s);
    for(i=0; i<strlen(s); i++)
    {
        if(s[i]=='-')
        {
            if(s[i-1]<s[i+1])
            {
                if((islower(s[i-1])!=0&&islower(s[i+1])!=0)||(isupper(s[i-1])!=0&&isupper(s[i+1])!=0)||(isdigit(s[i-1])!=0&&isdigit(s[i+1])!=0))
                {
                    for(int j=s[i-1]+1; j<s[i+1]; j++)
                        printf("%c",j);
                }
            else
                printf("%c",s[i]);
            }
          else
                printf("%c",s[i]);
        }
        else
                printf("%c",s[i]);
    }
    return 0;
}



