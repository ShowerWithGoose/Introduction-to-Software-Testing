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
    for(i=0;num[i]!='.';i++) // @@ The loop finds the position of the decimal point. For "0.00...", i will be 1.

    {

    }
    if(i==1&&num[0]!='0') // @@ This condition handles numbers like "5.123". It prints the number as is with e0, which is incorrect for scientific notation if there are digits after decimal, but let's look at the failing case.
    {printf("%se0",num);
    }
    else if(i==1&&num[0]=='0') // @@ This block handles numbers like "0.00...". This is the relevant block for the input "0.00000009123456789012".
    {
    for(int x=2;x<len;x++) // @@ Iterates through digits after "0.".
    {
      if(num[x]=='0')
      count++; // @@ Counts leading zeros after the decimal point.
      else
      result[j++]=num[x+1]; // @@ ERROR: When the first non-zero digit is found at index x (e.g., '9' at index 9), this line copies the character at x+1 ('1') into result, skipping the significant digit '9'. It should copy num[x].
    }
    if(result[0]!=0) // @@ Checks if result has content. Note: result is not null-terminated properly or initialized, but logic flow is the main issue.
    printf("%c.%se-%d",num[count+2],result,count+1); // @@ ERROR: num[count+2] calculates the index of the first non-zero digit correctly (2 + count). However, because 'result' was populated incorrectly (skipping the first sig digit), the output is wrong. Also, the exponent calculation 'count+1' is correct for 0.00...d format (e.g., 0.009 -> 9e-3, count=2, exp=3). But wait, standard scientific notation for 0.009 is 9e-3. Input 0.00000009... has 7 zeros. count=7. Exp should be 8. The code prints e-(count+1) which is e-8. This part is actually correct for the exponent value. The main error is the missing significant digit in the mantissa.
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
    printf("%c.%se%d",num[0],result,i-1);}

    return 0;
}