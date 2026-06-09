#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>

char str[200];

int main()
{
    int i=0,j=0,cnt_f=0,cnt_b=0,flag=0;
    
    while(str[i]=getchar()) // @@ Assignment in condition may trigger compilation error with strict flags (-Werror=parentheses); also fails to null-terminate the string.
    {
        if(str[i]=='\n') // @@ Loop breaks here but does not append '\0', causing strlen to read out of bounds and potentially crash.
        {
            break;
        }
        if(str[i]=='.')
        {
            flag=1;
        }
        if(flag==0)
        {
            cnt_f++;
        }
        else
        {
            cnt_b++; // @@ Incorrectly counts the decimal point as a fractional digit, skewing length calculations.
        }
        i++;
    }
    
    if(str[0]=='0')
    {
        for(i=2;i<strlen(str);i++) // @@ strlen is unsafe without null terminator; assumes input strictly starts with "0.".
        {
            if(str[i]!='0')
            {
                printf("%c",str[i]);
                break;
            }
        }
        if(i<strlen(str)-2) // @@ strlen includes newline character, causing off-by-one error in boundary check.
        {
            printf(".");
        }
        for(j=i;j<strlen(str)-2;j++) // @@ Incorrect loop bound excludes the last significant digit of the number.
        {
            printf("%c",str[j]);
        }
        printf("e-%d",i-1); // @@ Exponent calculation is incorrect for inputs like 0.01 (should be -2, gives -1).
    }
    else if(str[0]!='-')
    {
        printf("%c.",str[0]);
        for(i=1;i<strlen(str)-1;i++) // @@ strlen includes newline, so -1 skips the last digit of the number.
        {
            if(str[i]=='.')
            {
                continue;
            }
            printf("%c",str[i]);
        }
        printf("e%d",cnt_f-1); // @@ Fails for integers without a decimal point (e.g., input "5" has no '.', cnt_f logic breaks).
    }
    else
    {
        printf("-");
        if(str[1]=='0')
        {
            for(i=3;i<strlen(str);i++) // @@ Same null-termination and fixed-format assumption issues as above.
            {
                if(str[i]!='0')
                {
                    printf("%c",str[i]);
                    break;
                }
            }
            if(i<strlen(str)-2) // @@ Off-by-one error due to newline being counted in strlen.
            {
                printf(".");
            }
            for(j=i;j<strlen(str)-2;j++) // @@ Excludes the last significant digit.
            {
                printf("%c",str[j]);
            }
            printf("e-%d",i-2); // @@ Incorrect exponent calculation for negative small numbers.
        }
        else
        {
            printf("%c.",str[1]);
            for(i=2;i<strlen(str)-1;i++) // @@ Skips last digit due to incorrect newline handling in loop bound.
            {
                if(str[i]=='.')
                {
                    continue;
                }
                printf("%c",str[i]);
            }
            printf("e%d",cnt_f-2); // @@ Incorrect exponent for negative numbers >= 1.
        }
    }
    return 0;
}