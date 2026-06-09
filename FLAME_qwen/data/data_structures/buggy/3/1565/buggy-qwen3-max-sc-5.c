#include<stdio.h>
#include<string.h>
int main()
{
    char s[1000],str[1000];
    int a=0;
    gets(s); // @@ [Using 'gets' is unsafe and deprecated; may cause compilation error in modern compilers due to removal from standard library]
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
                break;
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
                    a++; // @@ [This increment is misplaced; it's outside the inner loop but inside the else-if, leading to incorrect exponent calculation]
                str[0]=s[0];
                str[1]=s[i];
                break;
            }
        }
    }
    printf("%se%d",str,a); // @@ [The output format may be incorrect because 'str' might not be null-terminated, leading to undefined behavior or wrong output]
    return 0;
}