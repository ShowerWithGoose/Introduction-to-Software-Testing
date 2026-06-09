#include<stdio.h>
#include<string.h>
int main()
{
    char s[1000],str[1000];
    int a=0;
    gets(s);
    if(s[0]=='0')
    {
        for(int i=2;i<strlen(s);i++)
        {
            a--;
            if(s[i]!='0')
            {
                str[0]=s[i];
                if(i<strlen(s)-1)
                {
                    for(int j=i+1;j<strlen(s);j++)
                        str[j-i+1]=s[j];
                    str[1]='.';
                }
                break; // @@ Missing null terminator for str; causes undefined behavior when printing.
            }
        }
    }
    else
    {
        for(int i=strlen(s);i>=1;i--)
        {
            if(s[i]!='.')
            {
                str[i]=s[i];
            }
            else if(s[i]=='.')
            {
                for(int j=2;j<=i;j++)
                    str[j]=s[j-1];
                    a++; // @@ Incorrect exponent calculation; should be a = i-1 (number of digits before decimal minus one).
                str[0]=s[0];
                str[1]=s[i];
                break;
            }
        }
    }
    printf("%se%d",str,a);
    return 0;
}