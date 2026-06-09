#include<stdio.h>
#include<string.h>
#include<math.h>
#include<stdlib.h>
#include<ctype.h>
#include<time.h>
int main()
{
    char s[105];
    int i,j,k;
    gets(s); // @@ [Using 'gets' is unsafe and deprecated; it was removed in C11 and causes compilation errors with modern compilers. Use 'fgets' instead.]
    for(i=0;i<strlen(s);i++)
    {
        if(s[i]=='.')
        {
            if(s[i-1]!='0')
            {
                printf("%c.",s[0]);
                for(j=1;j<i;j++)
                {
                    printf("%c",s[j]);
                }
                for(j=i+1;j<strlen(s);j++)
                {
                    printf("%c",s[j]);
                }
                printf("e%d",i-1);
            }
            else
            {
                for(j=2;j<strlen(s);j++)
                {
                    if(s[j]!='0')
                    {
                        k=j;
                        break;
                    }
                }
                for(j=k;j<strlen(s);j++)
                {
                    printf("%c",s[j]);
                }
                printf("e-%d",k-1); // @@ [If the input is "0.0", the loop never sets 'k', leading to undefined behavior when using uninitialized 'k'. Also, missing handling for numbers >= 1 with leading zeros like "01.23", which violates input assumptions but may still cause logic issues.]
            }
        }
    }
    return 0;
}