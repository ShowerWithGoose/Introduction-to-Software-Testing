#include<stdio.h>
#include<string.h>
char str[101];

int main()
{
    gets(str); // @@ gets() is unsafe and may cause buffer overflow; also, it's not standard C and may not be available in all compilers
    int len,k,flag=0;
    len=strlen(str);
    if(str[0]!='0')
        {
        printf("%c.",str[0]);
        for(k=1;k<len;k++)
        {
            if(str[k]!='.')
            {
                printf("%c",str[k]);
            }
            else flag=k; // @@ flag is set to the position of the decimal point, but this assignment is inside the loop and only updates when '.' is encountered; however, the loop continues printing digits after the decimal point, which is correct for the base, but the exponent calculation uses flag-1, which may be incorrect if there are multiple '.' or if the decimal point is not found
        }
        printf("e%d",flag-1); // @@ flag-1 gives the exponent, but if the input has no decimal point (e.g., "123"), flag remains 0, and flag-1 = -1, which is incorrect; also, for numbers like "12.34", flag is set to 2 (position of '.'), so flag-1 = 1, which is correct, but the loop prints all digits including the decimal point, which is wrong because the decimal point should be removed from the base
        
        }
    else{
        for(k=2;k<len;k++)
        {
            if(str[k]!='0')
            {
                printf("%c",str[k]);    
                break;
            }
        }
        if(k!=len-1) // @@ This condition checks if k is not the last index, but k is the index of the first non-zero digit after the decimal point; if the number is "0.001", k=4 (pointing to '1'), and len=5, so k!=len-1 is false, and the code skips printing the decimal point and remaining digits, which is incorrect because it should print ".1" for the base
        {
            printf(".");
            for(int i=k+1;i<len;i++)
            {
                printf("%c",str[k]); // @@ This prints str[k] (the same character) repeatedly instead of str[i]; it should be printf("%c", str[i]);
            }
        }
        printf("e-%d",k-1); // @@ k-1 gives the exponent, but for "0.001", k=4, so k-1=3, which is correct (e-3), but for "0.0", the loop never finds a non-zero digit, so k remains at its initial value (2), leading to incorrect exponent; also, the code does not handle the case where the number is "0" or "0.0" properly
    }
    return 0;
    
}