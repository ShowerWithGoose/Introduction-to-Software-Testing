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
    if(i==1&&num[0]!='0')
    {printf("%se0",num);
    }
    else if(i==1&&num[0]=='0')
    {
    for(int x=2;x<len;x++)
    {
      if(num[x]=='0')
      count++;
      else
      result[j++]=num[x+1]; // @@ Error: When the first non-zero digit is found at index x, we should copy num[x], not num[x+1]. Copying num[x+1] skips the first significant digit and shifts the rest, causing data loss and incorrect output (e.g., skipping '9' in 0.00...912...).
    }
    if(result[0]!=0) // @@ Logic Error: result is a string. Checking result[0]!=0 checks if the character is not NULL. However, due to the previous error, result might be empty or incorrect. Also, if the number is like 0.005, result would be "5". result[0] is '5'. '5' != 0 is true. This part intends to check if there are digits after the first significant one. But the indexing into result is flawed because j increments only when non-zero is found. If input is 0.005, x=3 is '5'. result[0]='5'. j=1. Loop ends. result is "5". The condition result[0]!=0 is true. It prints "%c.%se-%d". This implies it thinks there are more digits. But result contains all remaining digits. The logic for splitting base and fractional part is confused here.
    printf("%c.%se-%d",num[count+2],result,count+1); // @@ Error: num[count+2] is intended to be the first non-zero digit. If count=7 (for 0.00000009...), num[9] is '9'. This part is correct for the base digit. However, 'result' contains the wrong substring due to the earlier off-by-one error.
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