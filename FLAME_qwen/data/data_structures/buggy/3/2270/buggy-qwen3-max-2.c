#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>

char str[100001];

int main()
{
    scanf("%s",&str); // @@ [Using &str is incorrect; str is already a pointer to char array, should be scanf("%s", str);]
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
                printf("%c",str[i]); // @@ [Missing decimal point and exponent handling when last non-zero digit is at end; also control falls through without setting 'a' properly]
            }
        }
        e:
        printf("e-");
        printf("%d",a-1); // @@ [If all digits after decimal are zero (not possible per problem but logic flawed), 'a' remains 0 leading to wrong exponent; also missing newline]
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
        printf("%d",a-1); // @@ ['a' may be uninitialized if input has no decimal point, leading to undefined behavior; also missing newline]
    }
    
    return 0;
}