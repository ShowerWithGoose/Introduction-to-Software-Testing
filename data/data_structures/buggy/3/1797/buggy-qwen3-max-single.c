#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main()
{
    char num[1000];
    char result[1000];
    gets(num); @@ [Using gets() is unsafe and deprecated; may cause compilation error with modern compilers due to removal from C11 standard]
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
      result[j++]=num[x+1]; @@ [Incorrect indexing: should be num[x], not num[x+1]; this skips the first non-zero digit and causes wrong mantissa]
    }
    if(result[0]!=0) @@ [Incorrect condition: result[0]!=0 compares against null character value, but result may not be null-terminated; also logic flawed for single-digit case]
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
    printf("%c.%se%d",num[0],result,i-1);} @@ [Missing null-termination of result array; leads to undefined behavior when printing]

    return 0;
}