#include <stdio.h>
#include <string.h>
char arr[105];
int main()
{
    scanf("%s",arr);
    int i=0;
    
    if(arr[0]>'0')
    {
        for(i=1;i<strlen(arr);i++)
        {
            if(arr[i]=='.')
            {
                break;
            }
        }
        printf("%d.",arr[0]-'0'); // @@ [Using %d prints an integer followed by '.', but if the number has only one digit before decimal and no fractional part originally, this may incorrectly force a decimal point. Also, for numbers like "5.0", it would print "5." which is acceptable per problem, but logic fails for cases where input is just "5" (no decimal). However, main issue is in exponent calculation and handling of non-zero leading digit case when there's no decimal point in input.]
        for(int j=1;j<strlen(arr);j++)
        {
            if(arr[j]!='.')
            {
                putchar(arr[j]);
            }
        }
        printf("e%d",i-1); // @@ [If input has no decimal point (e.g., "123"), loop doesn't find '.' so 'i' becomes strlen(arr), leading to wrong exponent. Problem states input always has digits before and after decimal point, so maybe not triggered, but still fragile. However, bigger issue is in else branch.]
        
    }
    else
        {
            for(i=1;i<strlen(arr);i++)
            {
                if(arr[i]!='0'&&arr[i]!='.')
                {
                    break;
                }
            }
            if(arr[strlen(arr)-2]=='0'&&arr[strlen(arr)-2]=='.') // @@ [This condition is logically flawed: arr[strlen(arr)-2]=='.', then comparing same element to '0' will never be true. It should check if the significant digit found is the last character (i.e., no digits after it), but current logic is broken and causes incorrect output format (missing decimal point when needed or vice versa). Also, arr[strlen(arr)-2] assumes at least two characters before end, which may not hold.]
            {
                printf("%d",arr[i]-'0');
            }
            else
            {
                printf("%d.",arr[i]-'0');
            }
            for(int j=i+1;j<strlen(arr);j++)
            {
                if(arr[j]!='.')
                {
                    putchar(arr[j]);
                }
            }
            printf("e-%d",i-1); // @@ [Exponent should be (i - position_of_decimal - 1). Since decimal is at index 1 for "0.xxx", exponent is -(i - 2). Current code uses i-1, which is off by one. For example, input "0.001" -> first non-zero at i=3, exponent should be -3, but code prints e-2.]
            
        }
    
    
    
    return 0;
}