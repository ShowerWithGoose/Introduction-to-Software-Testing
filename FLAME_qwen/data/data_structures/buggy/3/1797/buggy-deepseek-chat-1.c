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
      result[j++]=num[x+1]; // @@ [Error: This line incorrectly skips the current non-zero digit and starts from the next character, causing loss of data. It should be result[j++]=num[x];]
    }
    if(result[0]!=0)
    printf("%c.%se-%d",num[count+2],result,count+1); // @@ [Error: result is a character array, not a string; using %s will print garbage. Also, num[count+2] may be out of bounds if count is large. The logic for extracting the first significant digit is flawed.]
    else
    printf("%ce-%d",num[count+2],count+1); // @@ [Error: Same issue with num[count+2] potentially out of bounds, and the format does not match the required scientific notation (missing decimal point and 'e' placement).]
    }
    else
    {
        for(int x=1;x<len;x++)
        {
            if(num[x]!='.')
            result[j++]=num[x];
            
        }
    printf("%c.%se%d",num[0],result,i-1);} // @@ [Error: result is not null-terminated, so %s will print garbage. Also, the exponent should be i-1 only if the decimal point is at position i, but the loop may not handle cases where there are leading zeros correctly.]

    return 0;
}