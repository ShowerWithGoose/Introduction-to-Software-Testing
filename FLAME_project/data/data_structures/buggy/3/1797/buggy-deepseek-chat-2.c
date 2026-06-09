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
    {printf("%se0",num);
    }
    else if(i==1&&num[0]=='0')
    {
    for(int x=2;x<len;x++)
    {
      if(num[x]=='0')
      count++;
      else
      result[j++]=num[x+1]; // @@ Error: This line incorrectly skips the first non-zero digit and starts from the next character, causing the output to miss the first significant digit. It should be `result[j++]=num[x];` and then handle the remaining digits properly.
    }
    if(result[0]!=0)
    printf("%c.%se-%d",num[count+2],result,count+1); // @@ Error: `num[count+2]` does not correctly point to the first non-zero digit; it should be `num[count+2]` only if count is the number of zeros after the decimal point, but the logic is flawed. Also, `result` may contain extra characters or be empty, leading to incorrect output.
    else
    printf("%ce-%d",num[count+2],count+1); // @@ Error: Same issue with `num[count+2]`; it does not correctly identify the first non-zero digit. The exponent calculation `count+1` is also incorrect for the given input.
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