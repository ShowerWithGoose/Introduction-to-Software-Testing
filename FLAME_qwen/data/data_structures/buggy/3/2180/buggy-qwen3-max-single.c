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
    gets(s); // @@ [The function 'gets' is unsafe and has been removed from the C standard library since C11; using it may cause compilation errors or warnings with modern compilers.]
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
                printf("e-%d",k-1); // @@ [If all digits after the decimal point are zero (e.g., "0.000"), the loop above never sets 'k', leading to undefined behavior when using uninitialized variable 'k'. Also, this branch assumes there's at least one non-zero digit after leading zeros, which may not be true per problem constraints, but the problem states all digits are significant so trailing zeros won't exist—but leading zeros might be all that's present only if followed by non-zero, yet code doesn't handle case where no non-zero found.]
            }
        }
    }
    return 0;
}