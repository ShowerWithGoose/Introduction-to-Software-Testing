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
    gets(s);
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
                    printf("%c",s[j]); // @@ [This prints all digits from the first non-zero after decimal as integer part, but scientific notation requires only one digit before decimal point followed by a decimal point and the rest of significant digits.]
                }
                printf("e-%d",k-1); // @@ [The exponent calculation is incorrect; it should be -(k - 1) where k is index of first non-zero digit after decimal, but since we are printing multiple digits before 'e', the format violates scientific notation rules. Also, the loop above doesn't stop at the last non-zero digit, possibly including trailing zeros which shouldn't be there per problem statement.]
            }
        }
    }
    return 0;
}