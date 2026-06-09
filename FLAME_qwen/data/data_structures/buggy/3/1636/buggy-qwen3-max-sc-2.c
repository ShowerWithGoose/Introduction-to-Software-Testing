#include <stdio.h>
#include <string.h>
char s[105];
int main()
{
    scanf("%s",&s); // @@ [Using &s is incorrect; s is already a pointer to char array, should be scanf("%s", s);]
    int i,j;
    if(s[1]=='.')
    {
        if(s[0]!='0')
        {
            for(i=0;i<strlen(s);i++)
            {
                printf("%c",s[i]);
            }
            printf("e0");    
        }
        else
        {
            for(i=2;i<strlen(s);i++)
            {
                if((s[i]!='0')&&(i!=strlen(s)-1))
                {
                    printf("%c.",s[i]); // @@ [This prints only one digit before decimal but doesn't handle cases where trailing zeros might exist or input ends with non-zero correctly per problem spec]
                    for(j=i+1;j<strlen(s);j++)
                    {
                        printf("%c",s[j]);
                    }
                    printf("e%d",i-1); // @@ [Exponent should be negative when leading zeros are skipped after decimal point (e.g., 0.001 -> 1e-3), but here it's printed as positive]
                    break;
                }
                else if(i==strlen(s)-1)
                {
                    printf("%ce-%d",s[i],i-1);
                }
            }
        }
    }
    else
    {
        for(i=0;i<strlen(s);i++)
        {
            if(s[i]=='.')
            {
                printf("%c.",s[0]);
                for(j=1;j<=i-1;j++)
                {
                    printf("%c",s[j]);
                }
                for(j=i+1;j<strlen(s);j++)
                {
                    printf("%c",s[j]);
                }
                printf("e%d",i-1); // @@ [This assumes there's always a decimal point in the input, but problem states input always has digits before and after decimal, so this may be okay, but logic fails for numbers like "123.45" which should become "1.2345e2", not "1.2345e2" with i=3 => e2 correct, however missing handling of case when number has no decimal? But problem says it always has. However, the bigger issue is that this branch doesn't handle numbers without decimal at all, but problem guarantees decimal exists. Still, the main bugs are in the zero-leading case.]
                break;
            }
        }
    }
    return 0;
}