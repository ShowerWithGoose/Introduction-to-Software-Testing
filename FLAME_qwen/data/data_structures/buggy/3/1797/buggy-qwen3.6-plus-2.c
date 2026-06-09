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
      result[j++]=num[x+1]; // @@ Logic error: incorrectly accesses num[x+1] instead of num[x], skipping the current non-zero digit and potentially causing out-of-bounds access.
    }
    if(result[0]!=0) // @@ Logic error: compares character to integer 0 instead of null terminator '\0'; additionally, result is never null-terminated, leading to undefined behavior when used with %s.
    printf("%c.%se-%d",num[count+2],result,count+1);
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
    printf("%c.%se%d",num[0],result,i-1);} // @@ Logic error: result array is not null-terminated, causing %s to print garbage data beyond the intended string.

    return 0;
}