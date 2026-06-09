#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>

char str[100001];

int main()
{
    scanf("%s",&str); // @@ [Using &str is incorrect; str is already a pointer to char array. Should be scanf("%s", str);]
    int len = strlen(str);
    int a = 0;
    if(str[0]-'0'==0)
    {
        for(int i=2;i<len;i++)
        {
            if(str[i]!='0'&&str[i+1]!='\0')
            {
                printf("%c.",str[i]);
                a = i;
                for(int p=i+1;p<len;p++)
                {
                    printf("%c",str[p]);
                }
                goto e;
            }
            else if(str[i]!='0'&&str[i+1]=='\0')
            {
                printf("%c",str[i]); // @@ [Missing decimal point and exponent handling when the non-zero digit is the last character; this branch prints only the digit without 'e' notation]
            }
        }
        e:
        printf("e-");
        printf("%d",a-1);
    }
    else
    {
        printf("%c.",str[0]);
        for(int i=1;i<len;i++)
        {
            if(str[i]!='.')
            {
                printf("%c",str[i]);
            }
            else
            {
                a = i;
            }
        }
        printf("e");
        printf("%d",a-1); // @@ [If input has no decimal point (though problem says it does), 'a' remains 0, leading to wrong exponent. Also, if number is like "5" (but per problem there's always a decimal), logic may fail. However, main issue: when non-zero integer part exists, trailing zeros after decimal may be printed, violating "no trailing zeros" rule. But more critically, if input is like "10.0", but problem states all digits are significant and no trailing zeros, so maybe not. However, the bigger flaw is in the zero-leading case above.]
    }
    
    return 0;
}