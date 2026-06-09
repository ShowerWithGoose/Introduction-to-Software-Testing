#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main()
{
    char num[1000];
    char result[1000];
    gets(num);
    int len =strlen(num);
    int i=0,j=0,count=0;
    for(i=0;num[i]!='.';i++)
    {

    }
    if(i==1&&num[0]!='0')
    {printf("%se0",num); // @@ This prints the original number as the base with exponent 0, but scientific notation requires moving the decimal point if the integer part has more than one digit (e.g., "123.456" should become "1.23456e2").
    }
    else if(i==1&&num[0]=='0')
    {
    for(int x=2;x<len;x++)
    {
      if(num[x]=='0')
      count++;
      else
      result[j++]=num[x+1]; // @@ Storing num[x+1] for each non-zero digit skips the first non-zero digit itself, but the base's first digit is taken separately from num[count+2]. However, the exponent calculation becomes incorrect because the loop does not break after the first non-zero and continues storing, potentially causing index out-of-bounds when x = len-1 (num[x+1] accesses num[len], which is the null terminator). More critically, the overall logic leads to a wrong number of leading zeros and exponent offset.
    }
    if(result[0]!=0) // @@ This compares a character to integer 0, which is not the intended check for an empty string. It should be `if(result[0]!='\0')` or `if(j>0)`. This may cause the decimal point to be printed even when there are no digits after the first non-zero, or incorrectly treat a null character as non-zero.
    printf("%c.%se-%d",num[count+2],result,count+1); // @@ The exponent is printed as -(count+1), but the actual exponent for the given input should be -8, while this outputs -9. This is because count is incremented incorrectly (it counts zeros up to the first non-zero, but due to the flawed loop structure it may count one extra zero or the indexing of the first digit is off).
    else
    printf("%ce-%d",num[count+2],count+1);
    }
    else
    {
        for(int x=1;x<len;x++)
        {
            if(num[x]!='.')
            result[j++]=num[x];
            
        }
    printf("%c.%se%d",num[0],result,i-1);} // @@ For numbers with more than one digit before the decimal, this correctly prints the first digit, a decimal point, all remaining digits, and the exponent. However, if the number is negative (which the problem does not require handling), this branch would be taken incorrectly.

    return 0;
}