#include <stdio.h>
char str[10000];
int main()
{
    gets(str); // @@ [Using 'gets' is unsafe and deprecated; may cause compilation error with modern compilers due to removal from C11 standard]
    int i=1,j;
    if(str[0]=='0')
    {
        for(i=2;str[i]=='0';i++); // @@ [Incorrect loop start index: should start from i=1 (after '0.') not i=2; also fails to handle the decimal point correctly]
        if(str[i+1]=='\0') // @@ [Potential out-of-bounds access if str[i] is '\0'; also logic doesn't account for decimal point position properly]
        {
            printf("%c",str[i]);
        }
        else
        {
            printf("%c.",str[i]);
            for(j=i+1;str[j]!='\0';j++)
            {
                printf("%c",str[j]);
            }    
            printf("e");
            printf("%d",i-1); // @@ [Exponent calculation is incorrect; does not count skipped zeros and decimal point correctly]
        }
    }
    else if(str[1]=='.') // @@ [This condition assumes second character is '.' but input like "123.45" would not match, yet it's valid; also misses cases like single digit without decimal]
    {
        for(i=0;str[i]!='\0';i++)
        {
            printf("%c",str[i]);
        }
        printf("e0"); // @@ [Output format violates specification: should be normalized to one non-zero digit before decimal, e.g., "1.23e2", not original form]
    }
    else
    {
        for(i=0;str[i]!='.';i++); // @@ [Loop starts at i=0 but then uses str[0] separately; however, loop reinitializes i=0 which overrides earlier i=1; also no check if '.' exists]
        printf("%c.",str[0]);
        for(j=1;j<i;j++)
        {
            printf("%c",str[j]);
        }
        for(j=i+1;str[j]!='\0';j++)
        {
            printf("%c",str[j]);
        }
        printf("e");
        printf("%d",i-1); // @@ [Exponent calculation may be off by one; for "123.45", i=3 ('.' at index 3), exponent should be 2, but i-1=2 is correct—however, logic fragile due to missing validation]
    }
    return 0;
}