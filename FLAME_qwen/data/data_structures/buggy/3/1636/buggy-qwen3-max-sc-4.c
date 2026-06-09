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
                    printf("%c.",s[i]); // @@ [This prints only one digit before decimal but doesn't handle trailing zeros correctly per problem spec; also logic for exponent is flawed]
                    for(j=i+1;j<strlen(s);j++)
                    {
                        printf("%c",s[j]);
                    }
                    printf("e%d",i-1); // @@ [Exponent should be negative when leading zeros exist after decimal point, e.g., 0.00123 -> 1.23e-3, not e2]
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
                printf("e%d",i-1); // @@ [This assumes there's always a decimal point in the input, but problem says input has digits before and after decimal point, so this may be okay, but fails when number has no decimal? However problem states input always has decimal. Still, logic doesn't normalize to one non-zero digit before decimal when multiple digits exist before decimal. For example, input "123.45" should become "1.2345e2", but this outputs "1.2345e2" only if s[0] is first digit and rest are printed — actually this part seems partially correct, but misses cases where integer part has more than one digit and no decimal at position 1. However, the main issue is missing handling of numbers without decimal point? But problem says input always has decimal. So maybe not error here. However, the real flaw is that this branch assumes decimal exists somewhere, which is fine per problem, but the normalization is wrong: it prints s[0] then all digits from s[1] up to before decimal, then after — which gives more than one digit before decimal in base. E.g., "12.34" becomes "1.234e1", which is correct. Wait: s[0]='1', then j from 1 to i-1 (i=2), so j=1 prints '2', then after decimal '34' → "1.234e1" — that's correct. So maybe this part is okay. But what about "123.4"? i=3, prints s[0]='1', then j=1 to 2 → '2','3', then '4' → "1.234e2" — correct. So this branch might be okay. The major errors are in the zero-leading case and the scanf usage.]
                break;
            }
        }
    }
    return 0;
 }