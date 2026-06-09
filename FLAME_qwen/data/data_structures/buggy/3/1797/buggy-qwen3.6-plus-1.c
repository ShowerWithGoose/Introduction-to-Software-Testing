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
      result[j++]=num[x+1]; // @@ Off-by-one error: should copy num[x] instead of num[x+1], otherwise it skips the first non-zero digit after the decimal point.
    }
    if(result[0]!=0) // @@ Incorrect condition: compares character to integer 0 instead of '\0', and result array is not null-terminated.
    printf("%c.%se-%d",num[count+2],result,count+1); // @@ result lacks null-termination, causing %s to read out of bounds and print garbage or crash.
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
    printf("%c.%se%d",num[0],result,i-1);} // @@ result lacks null-termination, causing %s to read out of bounds and print garbage or crash.

    return 0;
}