#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>

char str[100001];

int main()
{
    scanf("%s",&str);
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
                printf("%c",str[i]); @@ // This branch prints only one digit without decimal point, but doesn't set 'a' correctly or handle exponent properly for single non-zero digit after zeros
                a = i; @@ // Missing assignment of 'a' in this branch leads to undefined exponent calculation
                goto e; @@ // Missing goto causes fall-through and incorrect exponent output
            }
        }
        e:
        printf("e-");
        printf("%d",a-1); @@ // When input is "0.9", a=2, so a-1=1, but it should be -1; exponent sign and magnitude are both wrong due to incorrect logic
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
        printf("%d",a-1); @@ // For numbers >=1, exponent should be (position of decimal point - 1), but this works only if decimal exists; however, problem states input always has decimal point, so this part may be okay, but overall logic inconsistent with scientific notation rules
    }
    
    return 0;
}