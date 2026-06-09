#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main()
{
    char num[1000];
    char result[1000];
    gets(num); // @@ [Using gets() is unsafe and deprecated; may cause buffer overflow. Also, in some environments, this leads to compilation errors or warnings that prevent execution.]
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
      result[j++]=num[x+1]; // @@ [Off-by-one error: should be num[x], not num[x+1]. This skips the first non-zero digit after leading zeros and may read beyond the string if x == len-1.]
    }
    if(result[0]!=0) // @@ [Incorrect check: result[0]!=0 compares against null character value but result may not be null-terminated. Also, logic fails when there's only one significant digit after zeros.]
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
    printf("%c.%se%d",num[0],result,i-1);} // @@ [result is not null-terminated, leading to undefined behavior when printed with %s. Also, exponent calculation i-1 is incorrect for numbers like "123.45" (should be 2, but i=3 so i-1=2 which is correct), but logic fails for other cases due to missing handling of decimal position.]

    return 0;
}